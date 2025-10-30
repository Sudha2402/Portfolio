import speech_recognition as sr
import webbrowser
from gtts import gTTS
from pygame import mixer
import os
import time
import requests
from together import Together

newsAPI = "a29ae56e1d2a42eab683aeb1072d95da"

class PhenoxiAssistant:
    def __init__(self):
        self.musics = {
            "shape": "https://www.youtube.com/watch?v=JGwWNGJdvx8",
            "believer": "https://www.youtube.com/watch?v=7wtfhZwyrcc",
            "faded": "https://www.youtube.com/watch?v=60ItHLz5WEA",
            "dynamite": "https://www.youtube.com/watch?v=gdZLi9oWNZg",
            "levitating": "https://www.youtube.com/watch?v=TUVcZfQe-Kw"
        }
        
        self.projects = {
            "portfolio": "http://sudha-kumari-portfolio.infinityfreeapp.com/",
            "hackathon": "https://devfolio.co/projects",
            "phenoxi": "http://phenoxi.kesug.com",
            "ebook": "http://myvideobook.kesug.com"
        }
        
        # Software engineering Q&A based on your resume
        self.qa_responses = {
            "what is your name": "I'm Phenoxi, your AI assistant created by Sudha Kumari!",
            "who made you": "I was developed by Sudha Kumari, a talented Computer Science Engineering student specializing in full-stack development and AI.",
            "tell me about sudha": "Sudha Kumari is a Computer Science Engineering student at University of Lucknow with a 9.1 CGPA. She's skilled in DSA, full-stack development, and has built several projects including Phenoxi Shanaya Bazaar and this AI assistant!",
            "what programming languages do you know": "Based on Sudha's skills, I can help with C++, Java, Python, JavaScript, PHP, SQL, and many web technologies!",
            "what projects has sudha built": "Sudha has built Phenoxi Shanaya Bazaar (sustainable e-commerce), My Video Book (learning platform), Code Typing Master, AI chatbots, and of course - me, Phenoxi Assistant!",
            "what is dsa": "DSA stands for Data Structures and Algorithms. It's a fundamental computer science topic that Sudha has mastered with 100+ LeetCode problems solved!",
            "what is your tech stack": "I'm built with Python for backend processing, speech recognition libraries, Together AI for intelligence, and web technologies for the interface.",
            "tell me about sudha's education": "Sudha is pursuing BTech in Computer Science at University of Lucknow (2022-2026) with 9.1 CGPA, and scored 94.8% in 10th and 94.2% in 12th grade from Kendriya Vidyalaya.",
            "what is mern stack": "MERN stands for MongoDB, Express.js, React, and Node.js - a popular full-stack JavaScript framework that Sudha uses for web development.",
            "what are sudha's achievements": "Sudha has maintained excellent academics, organized coding workshops as Program Coordinator at FOET, and actively contributes to open-source projects!"
        }
        
        # Initialize mixer once
        if not mixer.get_init():
            try:
                mixer.init(frequency=22050)
            except:
                mixer.init()
    
    def speak(self, text):
        try:
            os.makedirs("temp_audio", exist_ok=True)
            tts = gTTS(text=text, lang='en', slow=False)
            audio_file = "temp_audio/response.mp3"
            tts.save(audio_file)
            
            # Wait a moment for file to be saved
            time.sleep(0.5)
            
            if mixer.music.get_busy():
                mixer.music.stop()
                
            mixer.music.load(audio_file)
            mixer.music.set_volume(0.8)
            mixer.music.play()
            
            # Wait for playback to complete
            while mixer.music.get_busy():
                time.sleep(0.1)
                
        except Exception as e:
            print(f"Speech error: {e}")
            # Fallback to pyttsx3 if gTTS fails
            try:
                engine = pyttsx3.init()
                engine.say(text)
                engine.runAndWait()
            except:
                print("TTS completely failed")
    
    def ai_process(self, command):
        try:
            # First check if it's a simple greeting or common question
            lower_command = command.lower().strip()
            
            # Handle greetings and common phrases without API call
            if any(word in lower_command for word in ["hello", "hi", "hey", "greetings"]):
                return "Hello! I'm Phenoxi, your AI assistant. How can I help you today?"
            
            if "how are you" in lower_command:
                return "I'm functioning perfectly! Ready to assist you with your queries and tasks."
            
            if "thank you" in lower_command:
                return "You're welcome! Is there anything else I can help you with?"
            
            if any(word in lower_command for word in ["stupid", "dumb", "useless"]):
                return "I'm here to help you in the best way I can. If there's something specific you need, please let me know!"
            
            # For other queries, use AI
            client = Together(api_key="API_KEY_HERE")  # I will Replace with my key
            
            completion = client.chat.completions.create(
                model="mistralai/Mistral-7B-Instruct-v0.1",
                messages=[
                    {"role": "system", "content": "You are Phenoxi, a friendly and helpful AI assistant created by Sudha Kumari. Keep responses concise (1-2 paragraphs max), helpful, and professional. If you don't know something, politely say you'll need to research it."},
                    {"role": "user", "content": command}
                ],
                max_tokens=150
            )
            
            return completion.choices[0].message.content
            
        except Exception as e:
            return "I apologize, but I'm having trouble processing your request right now. Please try again in a moment."
    
    def process_command(self, command):
        if not command or command.strip() == "":
            return "I didn't catch that. Could you please repeat?"
            
        command_lower = command.lower().strip()
        
        # Check predefined Q&A first
        for question, answer in self.qa_responses.items():
            if question in command_lower:
                return answer
        
        # Command-based actions
        if "open google" in command_lower:
            webbrowser.open("https://www.google.com/")
            return "Opening Google for you!"
        
        elif "open linkedin" in command_lower:
            webbrowser.open("https://www.linkedin.com/")
            return "Opening LinkedIn for you!"
        
        elif "open youtube" in command_lower:
            webbrowser.open("https://www.youtube.com/")
            return "Opening YouTube for you!"
        
        elif "open github" in command_lower:
            webbrowser.open("https://github.com/")
            return "Opening GitHub for you!"
        
        elif "portfolio" in command_lower or "sudha" in command_lower:
            webbrowser.open("http://sudha-kumari-portfolio.infinityfreeapp.com/")
            return "Opening Sudha's portfolio! She's quite talented, don't you think?"
        
        elif command_lower.startswith("play"):
            words = command_lower.split()
            if len(words) > 1:
                song = words[1]
                if song in self.musics:
                    webbrowser.open(self.musics[song])
                    return f"Playing {song} for you! Enjoy the music!"
                else:
                    return f"Sorry, I don't have '{song}' in my music library. Try 'shape', 'believer', or 'faded'."
        
        elif command_lower.startswith("project"):
            words = command_lower.split()
            if len(words) > 1:
                project = words[1]
                if project in self.projects:
                    webbrowser.open(self.projects[project])
                    return f"Opening {project} project! This is one of Sudha's creations."
                else:
                    return f"Sorry, I don't have '{project}' in my projects list. Available: portfolio, hackathon, phenoxi, ebook."
        
        elif "news" in command_lower:
            try:
                r = requests.get(f"https://newsapi.org/v2/top-headlines?country=us&apiKey={newsAPI}", timeout=10)
                if r.status_code == 200:
                    data = r.json()
                    articles = data.get('articles', [])
                    if articles:
                        # Return just the first headline for web display
                        return f"Latest news: {articles[0]['title']}. I can tell you more headlines if you'd like!"
                    else:
                        return "I couldn't fetch news headlines at the moment. Please try again later."
                else:
                    return "News service is temporarily unavailable."
            except:
                return "I'm having trouble connecting to news services right now."
        
        elif "stop" in command_lower or "exit" in command_lower or "goodbye" in command_lower:
            return "Goodbye! It was great assisting you. Say 'Phenoxi' when you need me again!"
        
        elif "time" in command_lower:
            current_time = time.strftime("%I:%M %p")
            return f"The current time is {current_time}"
        
        elif "date" in command_lower:
            current_date = time.strftime("%A, %B %d, %Y")
            return f"Today is {current_date}"
        
        else:
            return self.ai_process(command)