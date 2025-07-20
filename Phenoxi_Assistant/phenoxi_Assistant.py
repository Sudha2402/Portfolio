import speech_recognition as sr

import webbrowser #used for webfunctionalities like to open a new file
import pyttsx3
# import musicLibrary #used to select music from file defined
import os

import Database
import requests
# The requests module in Python is a popular third-party library used for making HTTP requests. It simplifies the process of interacting with web services and APIs by providing a user-friendly interface for common HTTP operations. 


from pygame import mixer
import time




def speak(text):
    
    # below commented way causes error as we neet to speak repeadilt, and initialized must be close
    
    # tts = gTTS(text)
    # # tts.save('response.mp3') #it is saving in external file as venv environment directory
    # tts.save('Phenoxi_Assistant/response.mp3') #when new response will be generated then it will be updated
    
    # # Starting the mixer
    # mixer.init()

    # # Loading the song
    # mixer.music.load("Phenoxi_Assistant/response.mp3")

    # # Setting the volume
    # mixer.music.set_volume(0.7)

    # # Start playing the song
    # mixer.music.play()
    

    # infinite loop #we don't need this
    # while True:
        
    #     print("Press 'p' to pause, 'r' to resume")
    #     print("Press 'e' to exit the program")
    #     query = input("  ")
        
    #     if query == 'p':

    #         # Pausing the music
    #         mixer.music.pause()     
    #     elif query == 'r':

    #         # Resuming the music
    #         mixer.music.unpause()
    #     elif query == 'e':

    #         # Stop the mixer
    #         mixer.music.stop()
    #         break
        
    # mixer.music.stop() #this way of stop will cause error, hence we will not use, we can use wait also if needed.
    
    
    try:
        # Ensure the directory exists
        os.makedirs("Phenoxi_Assistant", exist_ok=True)
        
        # Generate TTS and save the file
        tts = gTTS(text=text, lang='en')  # Explicitly set language
        audio_file = "Phenoxi_Assistant/response.mp3"
        tts.save(audio_file)
        
        # Initialize mixer (only once)
        if not mixer.get_init():
            mixer.init(frequency=22050)  # Standard frequency
            
        # Stop any currently playing audio
        mixer.music.stop()
        
        # Load and play new audio
        mixer.music.load(audio_file)
        mixer.music.set_volume(0.7)
        mixer.music.play()
        
        # Wait for playback to finish
        while mixer.music.get_busy():
            time.sleep(0.1)
            
        # Explicitly unload the file to release it
        mixer.music.unload()
        
    except Exception as e:
        print(f"Error in speak(): {e}")



def aiProcess(command):
    
    
    
    
    completion = client.chat.completions.create(
    model="moonshotai/Kimi-K2-Instruct",
    messages=[
        {"role": "system", "content": "You are a virtual assistant named phenoxi skilled in general tasks like Alexa and Google Cloud. Give short responses please"},
        {"role": "user", "content": command}
    ]
    )
    

    return completion.choices[0].message.content



def processCommand(command):
    # speak("Your search result for " , command , "is ready") #accepts single string arguement
    if("open google" in command.lower()):
        speak("Opening google")
        print("Opening google")
        webbrowser.open("https://www.google.com/")
    elif("open linkedIn" in command.lower()):
        speak("Opening LinkedIn")
        print("Opening LinkedIn")
        webbrowser.open("https://www.linkedin.com/")
    elif("open youtube" in command.lower()):
        speak("Opening youtube")
        webbrowser.open("https://www.youtube.com/")
    elif("portfolio" in command.lower() or "sudha" in command.lower()):
        speak("Opening Sudha's portfolio")
        print("Opening Sudha's portfolio")
        webbrowser.open("http://sudha-kumari-portfolio.infinityfreeapp.com/")
    elif command.lower().startswith("play"):
        
        song = command.lower().split(" ")[1]
        link = Database.musics[song]
        speak("playing your song")
        print("playing your song")
        webbrowser.open(link)
    elif command.lower().startswith("project"):
        
        project = command.lower().split(" ")[1]
        link = Database.projects[project]
        speak("Opening your project")
        print("Opening your project")
        webbrowser.open(link)
    
    elif "news" in command.lower():
        speak("Welcome to news")
        print("Welcome to news")
        
        if r.status_code == 200:
            # Parse the JSON response
            data = r.json()
            
            # Extract the articles
            articles = data.get('articles', [])
            
            # Print the headlines
            for article in articles:
                speak(article['title'])
        
    # elif("assitant" in command.lower()):
    #     #let open AI handle the request.
    #     print("Assistant")
    #     speak("Assitant will answer your questions")
    
    
        
    # elif("stop phenoxy" in command.lower()):
    elif("stop" in command.lower()):
        print("Stoping")
        speak("Stoping")
        return False  # Signal to stop
    
    
    else:
        # print("Assistant")
        speak("Your Phenoxi Assistant will answer your questions")
        output=aiProcess(command)
        print(output)
        speak(output)
        
    return True  # Continue listening
    




if __name__=="__main__" :
    # pass
    # speak("Welcome to Phenoxi")#we will do once user initialise it
    
    while True:  #keep initializing it
        # obtain audio from the microphone #it makes it keep listening as it gets initialized with very first true and not stops.hence some stop must be there to terminate it.
        
       
        
        
        # recognize speech using Google Speech Recognition
        
        print("listening")
        
        # speak("I am sudha")
        # speak("Welcome to phenoxi")
        
        try:
            
            # we kept this in try so that no error could be produced even when just listening the file
            r = sr.Recognizer()  #it is a class of speech_recognition
            with sr.Microphone() as source:
                print("Say something!")
            # audio = r.listen(source) #this listen function may take much time
            # audio = r.listen(source,timeout=2,phrase_time_limit=1) #we can set timeout upto 2sec hence listens for 2 seconds, #works good for single word command
            
                audio = r.listen(source) #it's working good in my case as I need long statements
            
            
            
            # for testing purposes, we're just using the default API key
            # to use another API key, use `r.recognize_google(audio, key="GOOGLE_SPEECH_RECOGNITION_API_KEY")`
            # instead of `r.recognize_google(audio)`
            print("Google Speech Recognition thinks you said " + r.recognize_google(audio))
            # speak(audio)no output
            # speak(r.recognize_google(audio)) #simpliy read out whatever is spoken
            
            openPhenoxi=r.recognize_google(audio)
            if(openPhenoxi.lower() == "phenoxi" or openPhenoxi.lower() == "phenoxy"):
            # if("phenoxi" in openPhenoxi or "phenoxy"  in openPhenoxi):
                
                # speak(r.recognize_google(audio))
                speak("Yes")
                
                #command to execute after yes
                
                print("Phenoxi Activated!")
                speak("Welcome to Phenoxi. How may I help you")
                
                while True: 
                    print("listening")
                    try:
                        
                        # r = sr.Recognizer() 
                        with sr.Microphone() as source:
                            print("Say something!")
                            audio = r.listen(source) #it's working good in my case as I need long statements
                            
                        print("Google Speech Recognition thinks you said " + r.recognize_google(audio))
                        command=r.recognize_google(audio)
                            
                            
                            #process command
                            
                        # processCommand(command)
                        # print("entered process command")
                        
                        if not processCommand(command):
                            break  # Exit the command loop if processCommand returns False
                        
                    except sr.UnknownValueError:
                        print("Google Speech Recognition could not understand audio")
            
                    except sr.RequestError as e:
                        print("Could not request results from Google Speech Recognition service; {0}".format(e))
                    except Exception as e:
                        print("Unknown error. Try later".format(e))
                     
                    
                
            
            
        except sr.UnknownValueError:
            print("Google Speech Recognition could not understand audio")
            
        except sr.RequestError as e:
            print("Could not request results from Google Speech Recognition service; {0}".format(e))
        except Exception as e:
            print("Unknown error. Try later".format(e))
    
    

#!/usr/bin/env python3

# NOTE: this example requires PyAudio because it uses the Microphone class





