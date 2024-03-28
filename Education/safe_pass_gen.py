import random

digits = "0123456789"
lowercase_letters = "abcdefghijklmnopqrstuvwxyz"
uppercase_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
punctuation = "!#$%&*+-=?@^_."
similar = "il1Lo0O"


def conditions():
    chars = ""
    number_of_passwords = int(input("Введите количество паролей для генерации: "))
    lenght = int(input("Введите длину одного пароля: "))
    enter_digits = input("Включать цифры? (y/n)\n")
    enter_lowercase = input("Включать строчные буквы? (y/n)\n")
    enter_uppercase = input("Включать заглавные буквы? (y/n)\n")
    enter_symbols = input("Включать символы? (y/n)\n")
    except_similar = input("Исключать необднозначные символы? (y/n)\n")
    if enter_digits.lower() == "y":
        chars += digits
    if enter_lowercase.lower() == "y":
        chars += lowercase_letters
    if enter_uppercase.lower() == "y":
        chars += uppercase_letters
    if enter_symbols.lower() == "y":
        chars += punctuation
    if except_similar.lower() == "y":
        for i in similar:
            chars.replace(i, "")
    return lenght, chars


def pass_gen(lenght, chars):
    for _ in range(lenght):
        password = ""
        for _ in range(lenght):
            password += random.choice(chars)
        print(password, "\n")


def start():
    lenght, chars = conditions()
    pass_gen(lenght, chars)


start()
