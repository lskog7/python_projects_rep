# СОРТИРОВКА ВЫБОРОМ

a = [
    78,
    -32,
    5,
    39,
    58,
    -5,
    -63,
    57,
    72,
    9,
    53,
    -1,
    63,
    -97,
    -21,
    -94,
    -47,
    57,
    -8,
    60,
    -23,
    -72,
    -22,
    -79,
    90,
    96,
    -41,
    -71,
    -48,
    84,
    89,
    -96,
    41,
    -16,
    94,
    -60,
    -64,
    -39,
    60,
    -14,
    -62,
    -19,
    -3,
    32,
    98,
    14,
    43,
    3,
    -56,
    71,
    -71,
    -67,
    80,
    27,
    92,
    92,
    -64,
    0,
    -77,
    2,
    -26,
    41,
    3,
    -31,
    48,
    39,
    20,
    -30,
    35,
    32,
    -58,
    2,
    63,
    64,
    66,
    62,
    82,
    -62,
    9,
    -52,
    35,
    -61,
    87,
    78,
    93,
    -42,
    87,
    -72,
    -10,
    -36,
    61,
    -16,
    59,
    59,
    22,
    -24,
    -67,
    76,
    -94,
    59,
]

n = len(a)


def selection_sort_v1(data):  # Тупая сортировка выбором
    for i in range(n):
        idx_min = i
        for j in range(i + 1, n):
            if data[j] > data[idx_min]:
                idx_min = j
        data[i], data[idx_min] = data[idx_min], data[i]
    return data


def selection_sort_v2(data):  # Сортировка выбором чуть-чуть поумнее
    for i, e in enumerate(data):  # i - index, e - number
        mx = max(range(i, len(data)), key=data.__getitem__)
        data[i], data[mx] = data[mx], e
    return data


def insertion_sort_v1(data):  # Тупая сортировка вставкой
    for i in range(len(data)):
        tmp = data[i]
        j = i
        while (data[j - 1] > tmp) and (j > 0):
            data[j] = data[j - 1]
            j = j - 1
        data[j] = tmp
    return data


def bubble_sort_v1(data):  # Тупая сортировка пузырьком
    for i in range(len(data), 0, -1):
        for j in range(1, i):
            if data[j - 1] > data[j]:
                tmp = data[j - 1]
                data[j - 1] = data[j]
                data[j] = tmp
    return a


def bingo_sort(data):
    max = len(data) - 1
    next_value = data[max]
    for i in range(max - 1, -1, -1):
        if data[i] > next_value:
            next_value = data[i]

    while max and data[max] == next_value:
        max -= 1

    while max:
        value = next_value
        next_value = data[max]
        for i in range(max - 1, -1, -1):
            if data[i] == value:
                data[i], data[max] = data[max], data[i]
                max -= 1
            elif data[i] > next_value:
                next_value = data[i]
            while max and data[max] == next_value:
                max -= 1

    return data


def cycle_sort(data):
    for cycle_Start in range(len(data) - 1):
        value = data[cycle_Start]
        pos = cycle_Start
        for i in range(cycle_Start + 1, len(data)):
            if data[i] < value:
                pos += 1
        if pos == cycle_Start:
            continue
        while value == data[pos]:
            pos += 1
        data[pos], value = value, data[pos]
        while pos != cycle_Start:
            pos = cycle_Start
            for i in range(cycle_Start + 1, len(data)):
                if data[i] < value:
                    pos += 1
            while value == data[pos]:
                pos += 1
            data[pos], value = value, data[pos]
    return data


def simple_insertion_sort(data):  # Сортировка простыми вставками
    n = len(data)
    for i in range(1, n):
        elem = data[i]
        j = i
        while j >= 1 and data[j - 1] > elem:
            data[j] = a[j - 1]
            j -= 1
        data[j] = elem
    return data


print(selection_sort_v1(a)[::-1])
