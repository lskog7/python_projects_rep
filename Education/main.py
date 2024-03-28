import math


def pascal(number):
    row = []
    for i in range(number + 1):  # число чисел в строке
        tmp = math.factorial(number) / (math.factorial(i) * math.factorial(number - i))
        row.append(tmp)
    return row


def main():
    n = int(input("Enter number of rows: "))
    for i in range(n):
        row = pascal(i)
        print(f"{i:<}:{row:^}")
        return 0


main()