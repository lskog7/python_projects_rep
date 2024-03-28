import webbrowser
import time
import pyautogui
import pyperclip
import pandas as pd
import pywhatkit as pwk
from datetime import datetime
import keyboard
import numpy as np


# Sending function
def send_whatsapp_message(phone_number, message):
    random_sleep_time = np.random.randint(3, 6)
    url = f"https://api.whatsapp.com/send?phone={phone_number}"
    webbrowser.open(url)
    time.sleep(random_sleep_time)
    pyautogui.press('enter')
    pyperclip.copy(message)
    # pyautogui.click()
    # pyautogui.hotkey('ctrlleft', 'v')
    keyboard.press_and_release('ctrl + v')
    time.sleep(random_sleep_time)
    pyautogui.press('enter')
    time.sleep(random_sleep_time)


# Function to send messages with pywhatkit
def pwk_message(number, message, wait_time):
    # Uncomment if you need to send not instantly and use different function
    # hour, minute = get_time()
    valid_number = '+' + number
    pwk.sendwhatmsg_instantly(valid_number, message, wait_time)
    print(f'Message sent to {number}!')


# Autosend function
def manual_send(df, message, count=0):
    # list_of_text = ""
    # first = False
    last_number = ''
    if count == 0:
        for idx in df.index:
            if df.loc[idx, "mark"] != 1:
                send_whatsapp_message(df.loc[idx, 'phone'], message)
                last_number = df.loc[idx, "phone"]
                # df.loc[idx, "mark"] = 1
                print(f'>>> Message to {df.loc[idx, "name"]} (Phone number -> {df.loc[idx, "phone"]}) is sent!')
    else:
        cnt = 0
        for idx in df.index:
            if cnt == count:
                break
            if df.loc[idx, "mark"] != 1:
                send_whatsapp_message(df.loc[idx, 'phone'], message)
                last_number = df.loc[idx, "phone"]
                # df.loc[idx, "mark"] = 1
                cnt += 1
                print(f'>>> Message to {df.loc[idx, "name"]} (Phone number -> {df.loc[idx, "phone"]}) is sent!')
                # list_of_text += f'>>> {df.loc[idx, "phone"]} --- message sent to {df.loc[idx, "name"]}'
    # log_to_file(list_of_text)
    file = open('last_number.txt', 'w+')
    try:
        file.write(str(last_number))
    finally:
        file.close()
    now = datetime.now()
    hours, minutes = get_time()
    print(f'>>> Finished at {hours} hours, {minutes} minutes.\n>>> Last number:\n>>> {last_number}')


# Test function
def test():
    test_number = '79060697274'
    test_message = 'Hello!\nIt is a test message.'
    send_whatsapp_message(test_number, test_message)


# Current time
def get_time():
    now = datetime.now()
    current_time = now.strftime("%H:%M").split(':')
    hours = int(current_time[0])
    minutes = int(current_time[1])
    # print(f'Hours = {hours}, Minutes = {minutes}')
    return hours, minutes


# General function to send message to everyone from dataframe (who is not marked)
def bot(df, message, wait_time):
    for idx in df.index:
        if df.loc[idx, 'mark'] != 1:
            pwk_message(str(df.loc[idx, 'phone']), message, wait_time)
            print(f'Message to {df.loc[idx, "name"]} (Phone number -> {df.loc[idx, "phone"]} is sent!')
            df.loc[idx, 'mark'] = 1
            time.sleep(10)
        else:
            continue


def log_to_file(list_of_text, file_name='log.txt'):
    file = open(file_name, 'w+')
    try:
            file.write(list_of_text)
    finally:
        file.close()


# Main cycle

# Testing data
test_number = ('79060697274')
test_message = (
    'Здравствуйте!\nВ 2023 году Вы участвовали в кейс-чемпионате Генериум.\nВ этом году, мы уже начали сбор заявок и будем очень рады Вашему участию, пожалуйста, переходите по ссылке и регистрируйтесь: https://generium-champ.ru (https://generium-champ.ru/).\nОт лица организационного комитета искренне желаем Вам удачи и конечно победы!')
wait_time = 5

# Testing block
# pwk_message(test_number, test_message, wait_time)
# send_whatsapp_message(test_number, test_message)
# c = 0
# for _ in range(10):
#     c += 1
#     send_whatsapp_message(test_number, test_message)
#     l = []
#     l.append(f'{c} >>>')
# log_to_file(l)

# Input data
df = pd.read_csv('prepared_data.csv')
message = (
    'Здравствуйте!\nВ 2023 году Вы участвовали в кейс-чемпионате Генериум.\nВ этом году, мы уже начали сбор заявок и будем очень рады Вашему участию, пожалуйста, переходите по ссылке и регистрируйтесь: https://generium-champ.ru.\nОт лица организационного комитета искренне желаем Вам удачи и, конечно, победы!\n\nССылка на телеграм канал чемпионата: https://t.me/championshipgenerium\nВСтупайте в наш чат в телеграм: https://t.me/+ssyS_BkqtKc4ZDcy')

# Spamming block
# bot(df, message, wait_time)
manual_send(df, message, 70)


# Main
# while True:
