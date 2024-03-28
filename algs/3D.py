def check_repeated_numbers(n, k, numbers):
    last_seen = {}

    for i, num in enumerate(numbers):
        if num in last_seen and i - last_seen[num] <= k:
            return "YES"
        last_seen[num] = i

    return "NO"

n, k = map(int, input().split())
numbers = list(map(int, input().split()))

result = check_repeated_numbers(n, k, numbers)
print(result)