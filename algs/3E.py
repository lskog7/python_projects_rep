n1 = int(input())
list1 = list(map(int, input().split()))
n2 = int(input())
list2 = list(map(int, input().split()))
n3 = int(input())
list3 = list(map(int, input().split()))
seen = dict()
for num in set(list1):
    seen[num] = 1
for num in set(list2):
    if num in seen:
        seen[num] += 1
    else:
        seen[num] = 1
for num in set(list3):
    if num in seen:
        seen[num] += 1
    else:
        seen[num] = 1
result = []
for num in seen:
    if seen[num] >= 2:
        result.append(num)
print(*sorted(set(result)))
