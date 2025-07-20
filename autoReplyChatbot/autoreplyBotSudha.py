
def is_last_message_from_receiver(chat_log, receiver_name = "Sudha"):
   
   
    if not chat_log.strip():
        return False
        
   
    lines = [line.strip() for line in chat_log.split('\n') if line.strip()]
    
    
    last_sender_line = None
    for line in reversed(lines):
        if '[' in line and ']' in line:
            last_sender_line = line
            break
    
    if not last_sender_line:
        return False
        
        
   
    name_part = last_sender_line.split(',')[0].strip()
    
   
    return receiver_name.lower() in name_part.lower()
    
    



    

pyautogui.click(774, 1063) 


time.sleep(1)



while True:
    time.sleep(5)
   
    pyautogui.moveTo(1888, 941)
    pyautogui.dragTo(524, 121, duration=2.0, button='left')  # Drag for 1 second

   
    pyautogui.hotkey('ctrl', 'c')
    time.sleep(2) 

    pyautogui.click(1855, 61) # 1855 61 to deselect the selected text

   
    chat_history = pyperclip.paste()

    # Print the copied text to verify
    print(chat_history)
    print(is_last_message_from_receiver(chat_history)) #False
    if not is_last_message_from_receiver(chat_history):
        completion = client.chat.completions.create(
        model="moonshotai/Kimi-K2-Instruct",
        messages=[
            {"role": "system", "content": "You are a person named Sudha who speaks hindi as well as english. You are from India and you are a coder. You analyze chat history and roast people in a funny way."},
            # {"role": "system", "content": "Do not start like this Sudha Shanaya World 🌎, [20-07-2025 11:29] "},
            {"role": "user", "content": chat_history}
        ]
        )
        
        
        response = completion.choices[0].message.content
        print(response)
        
        
   




