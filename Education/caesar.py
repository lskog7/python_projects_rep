import random

en_lower = "abcdefghijklmnopqrstuvwxyz"
en_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
ru_lower = "абвгдежзийклмнопрстуфхцчшщъыьэюя"
ru_upper = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"


def game():
    way, lang, step = choice()
    if way == "in":
        encrypt(lang, step)
    else:
        decrypt(lang, step)


def yes_or_no():
    print("Продолжаем? (y - да, n - нет)")
    answer = input()
    while True:
        if answer == "y":
            game()
        elif answer == "n":
            print("Всё пока!")
            break
        elif answer != "y" or answer == "n":
            print('Только "y" или "n"!')
            answer = input()


def choice():
    while True:
        way = input("Выберите направление (in - шифрование, out - дешифрование): ")
        if way == "in" or way == "out":
            break
        else:
            continue
    while True:
        lang = input("Выберите язык шифрования (ru - руссский, en - англиский): ")
        if lang == "ru" or lang == "en":
            break
        else:
            continue
    while True:
        step0 = input("Введите шаг шифрования (число от 1 до 26, 'r' для случайного): ")
        step1 = 0
        if step0 == "r":
            step1 = random.randrange(1, 26)
            print(f'Ваш шаг - {step1}')
            break
        elif step0.isdigit():
            step1 = step0
            break
        else:
            continue
    return way, lang, int(step1)


def encrypt(lang, step):
    source = input("Введите исходный текст: ")
    result = ""
    if lang == "ru":
        alphas = 32
        low_alphabet = ru_lower
        upp_alphabet = ru_upper
    elif lang == "en":
        alphas = 26
        low_alphabet = en_lower
        upp_alphabet = en_upper
    else:
        return 0
    for i in range(len(source)):
        place = 0
        if source[i].isalpha():
            if source[i] == source[i].lower():
                place = low_alphabet.index(source[i])
            elif source[i] == source[i].upper():
                place = upp_alphabet.index(source[i])
            index = (place + step) % alphas
            if source[i] == source[i].lower():
                result += low_alphabet[index]
            if source[i] == source[i].upper():
                result += upp_alphabet[index]
        else:
            result += source[i]
    print(f"Зашифрованный текст: {result}")
    yes_or_no()


def decrypt(lang, step):
    source = input("Введите исходный текст: ")
    result = ""
    if lang == "ru":
        alphas = 32
        low_alphabet = ru_lower
        upp_alphabet = ru_upper
    elif lang == "en":
        alphas = 26
        low_alphabet = en_lower
        upp_alphabet = en_upper
    else:
        return 0
    for i in range(len(source)):
        place = 0
        if source[i].isalpha():
            if source[i] == source[i].lower():
                place = low_alphabet.index(source[i])
            elif source[i] == source[i].upper():
                place = upp_alphabet.index(source[i])
            index = (place - step) % alphas
            if source[i] == source[i].lower():
                result += low_alphabet[index]
            if source[i] == source[i].upper():
                result += upp_alphabet[index]
        else:
            result += source[i]
    print(f"Дешифрованный текст: {result}")
    yes_or_no()


# Основная часть кода
game()
