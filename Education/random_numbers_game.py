import random


def yes_or_no():
    print("(y - да, n - нет)")
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


def is_valid(text, end):
    if text.isdigit() and 1 <= int(text) <= end:
        return True
    else:
        return False


def user_input_f(end):
    text = input()
    if is_valid(text, end):
        return int(text)
    elif text == "exit":
        return -1
    else:
        return 0


def game():
    print("Введите правую границу случайного номера (левая - 1):")
    while True:
        right_try = input()
        if right_try == "exit":
            print(
                "А чё ты решил заднюю то дать в середине игры, петушара? Ну пока, ЛОХ\nЛадно, последний шанс :"
            )
            yes_or_no()
        elif not right_try.isdigit():
            print("Ты еблан? Нормальные числа вводы, долбоеб!")
            continue
        else:
            right = int(right_try)
            break
    print("Введите своё число:")
    try_count = 0
    flag = True
    random_number = random.randrange(1, right)
    while flag:
        user_input = user_input_f(right)
        if user_input == 0:
            print("Ты еблан? Нормальные числа вводы, долбоеб!")
            continue
        elif user_input == -1:
            print(
                "А чё ты решил заднюю то дать в середине игры, петушара? Ну пока, ЛОХ\nЛадно, последний шанс :"
            )
            yes_or_no()
        else:
            try_count += 1
            if user_input > random_number:
                print("Число больше загаданного, давай по новой:")
                try_count += 1
                continue
            elif user_input < random_number:
                print("Число меньше загаданного, давай по новой:")
                try_count += 1
                continue
            elif user_input == random_number:
                print("Ебать ты Нострадамус!")
                flag = False
                print(
                    f"Спасибо, что играли в числовую угадайку. Число попыток: {try_count}. Хотите сыграть еще?"
                )
                yes_or_no()


print(
    "Добро пожаловать в числовую угадайку! (Для выхода из игры в процессе выбора введите 'exit')\nХотите сыграть?"
)
yes_or_no()
