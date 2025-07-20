import speech_recognition as sr

import webbrowser 
import pyttsx3
# import musicLibrary #used to select music from file defined
import os

import Database
import requests


from pygame import mixer
import time




def speak(text):
  
    
    
    try:
       
        os.makedirs("Phenoxi_Assistant", exist_ok=True)
        
      
        tts = gTTS(text=text, lang='en') 
        audio_file = "Phenoxi_Assistant/response.mp3"
        tts.save(audio_file)
        
     
        if not mixer.get_init():
            mixer.init(frequency=22050) 
            
      
        mixer.music.stop()
        
      
        mixer.music.load(audio_file)
        mixer.music.set_volume(0.7)
        mixer.music.play()
        
      
        while mixer.music.get_busy():
            time.sleep(0.1)
            
      
        mixer.music.unload()
        
    except Exception as e:
        print(f"Error in speak(): {e}")



def aiProcess(command):
    
    
    
    
    completion = client.chat.completions.create(
    messages=[
        {"role": "system", "content": "You are a virtual assistant named phenoxi skilled in general tasks like Alexa and Google Cloud. Give short responses please"},
        {"role": "user", "content": command}
    ]
    )
    

    return completion.choices[0].message.content



def processCommand(command):
    
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
           
            data = r.json()
            
           
            articles = data.get('articles', [])
            
           
            for article in articles:
                speak(article['title'])
        

        
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
           
                audio = r.listen(source) 
            
          
            print("Google Speech Recognition thinks you said " + r.recognize_google(audio))
           
            
            openPhenoxi=r.recognize_google(audio)
            if(openPhenoxi.lower() == "phenoxi" or openPhenoxi.lower() == "phenoxy"):
          
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
    



