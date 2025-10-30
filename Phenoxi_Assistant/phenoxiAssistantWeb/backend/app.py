from flask import Flask, request, jsonify, render_template
from flask_cors import CORS
from flask_socketio import SocketIO, emit
import speech_recognition as sr
import os
import time
import threading
from phenoxi_core import PhenoxiAssistant

app = Flask(__name__)
app.config['SECRET_KEY'] = 'phenoxi_secret_2024'
CORS(app)
socketio = SocketIO(app, cors_allowed_origins="*")

assistant = PhenoxiAssistant()

# Global variable to track listening state
is_listening = False
recognizer = sr.Recognizer()

@app.route('/')
def index():
    return render_template('index.html')

@socketio.on('connect')
def handle_connect():
    print('Client connected')
    emit('connection_status', {'status': 'connected', 'message': 'Welcome to Phenoxi!'})

@socketio.on('disconnect')
def handle_disconnect():
    print('Client disconnected')

@socketio.on('start_listening')
def handle_start_listening():
    global is_listening
    if not is_listening:
        is_listening = True
        emit('listening_status', {'status': 'active', 'message': '🎤 Listening...'})
        
        # Start voice recognition in a separate thread
        threading.Thread(target=voice_recognition_loop, daemon=True).start()

@socketio.on('stop_listening')
def handle_stop_listening():
    global is_listening
    is_listening = False
    emit('listening_status', {'status': 'inactive', 'message': '⏹️ Listening stopped'})

@socketio.on('text_command')
def handle_text_command(data):
    command = data.get('command', '')
    if command:
        response = assistant.process_command(command)
        emit('assistant_response', {
            'type': 'text',
            'content': response,
            'timestamp': time.time()
        })
        # Speak the response
        threading.Thread(target=assistant.speak, args=(response,), daemon=True).start()

def voice_recognition_loop():
    global is_listening, recognizer
    
    with sr.Microphone() as source:
        # Adjust for ambient noise once at start
        recognizer.adjust_for_ambient_noise(source, duration=1)
        recognizer.dynamic_energy_threshold = True
        recognizer.pause_threshold = 0.8
        
        while is_listening:
            try:
                socketio.emit('listening_status', {'status': 'processing', 'message': '🔊 Speak now...'})
                
                # Listen with shorter timeout to prevent false triggers
                audio = recognizer.listen(source, timeout=5, phrase_time_limit=4)
                
                text = recognizer.recognize_google(audio).lower()
                socketio.emit('user_speech', {
                    'text': text,
                    'timestamp': time.time()
                })
                
                # Add confidence check - ignore very short or common false triggers
                if len(text.split()) < 2 and any(word in text for word in ['google', 'open', 'okay', 'ok']):
                    socketio.emit('assistant_response', {
                        'type': 'info',
                        'content': "I heard a short command. Please speak clearly with more context.",
                        'timestamp': time.time()
                    })
                    continue
                
                # Process the command
                response = assistant.process_command(text)
                
                # Send response back to client
                socketio.emit('assistant_response', {
                    'type': 'voice',
                    'content': response,
                    'timestamp': time.time()
                })
                
                # Convert response to speech in separate thread
                threading.Thread(target=assistant.speak, args=(response,), daemon=True).start()
                
            except sr.WaitTimeoutError:
                continue
            except sr.UnknownValueError:
                socketio.emit('assistant_response', {
                    'type': 'error', 
                    'content': "Sorry, I didn't catch that. Please try speaking clearly.",
                    'timestamp': time.time()
                })
            except sr.RequestError as e:
                socketio.emit('assistant_response', {
                    'type': 'error',
                    'content': "Speech recognition service error. Please check your connection.",
                    'timestamp': time.time()
                })
            except Exception as e:
                socketio.emit('assistant_response', {
                    'type': 'error',
                    'content': f"Unexpected error: {str(e)}",
                    'timestamp': time.time()
                })

if __name__ == '__main__':
    socketio.run(app, debug=True, host='0.0.0.0', port=5000)