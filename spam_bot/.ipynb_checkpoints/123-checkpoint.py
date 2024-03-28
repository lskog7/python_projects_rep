import webbrowser
import time
import pyautogui
import pyperclip
import pandas as pd

# message_form = f"""Добрый день!
# Меня зовут Алексей, модератор проекта Новатор Москвы.
# Видели ваш проект «{name}» на платформе «Карта инновационных решений», и хотели бы рассказать про одну интересную возможность — принять участие в конкурсе Мэра Москвы с общим призовым фондом 20,7 млн. рублей (https://i.moscow/novator).
# Знаете про этот конкурс или рассказать подробнее?
# """

message_form1 = ', добрый день!'


def send_whatsapp_message(phone_number, message):
    # url = f"https://api.whatsapp.com/send?phone={phone_number}&text={message}"
    url = f"https://api.whatsapp.com/send?phone={phone_number}"
    webbrowser.open(url)
    time.sleep(3)
    pyperclip.copy(message)
    # pyautogui.moveTo(x=625, y=1000)
    # pyautogui.click()
    pyautogui.hotkey('ctrl', 'v')
    time.sleep(8)
    pyautogui.press('enter')
    time.sleep(2)


def contact(name, phone_number, message):
    message_form = f"""Добрый день!
Меня зовут Алексей, модератор проекта Новатор Москвы.
Увидел Ваш проект "{name}". Мне он очень понравился, хотел пригласить Вас принять участие в юбилейном конкурсе Мэра "Новатор Москвы" среди инновационных проектов, где Вы можете побороться за премию до 1,5 млн рублей.
Рассказать подробнее? Помогу заполнить заявку, при необходимости."""
    message = message_form
    send_whatsapp_message(phone_number, message)

# contact('Владимир', '79267674842', message_form)
df = pd.read_csv('out.csv')
print(df)
# 79251611061
contact('Алексей', '79378216816', message_form1)
for item in df.index:
    print(df.loc[item,'name'],df.loc[item,'phone'])
    contact(df.loc[item,'name'], df.loc[item,'phone'], message_form1)


