def number_to_ten():
    n = int(input("type n: "))
    number = input("type number: ")
    # result = int(number, n)
    result = 0
    count = 0
    while number != 0:
        last = number % 10
        result += last * (n**count)
        count += 1
        number //= 10
    print(f"number in ten: {result}")
    return result


def ten_to_number():
    result = ""
    base = int(input("type n: "))
    num = int(input("type number: "))
    while num:
        num, d = divmod(num, base)
        sd = str(d) if d < 10 else str(chr(ord("A") + d - 10))
        result = sd + result
    print(result)
    return result


def boh(number):
    print(bin(number)[2:])
    print(oct(number)[2:])
    print(hex(number)[2:].upper())


alpha_list = ["", "", "", "", "", "", "", "", "", "A", "B", "C", "D", "E", "F"]

boh(10)
