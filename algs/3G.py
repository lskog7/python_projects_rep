n = int(input())
points_lst = []
for i in range(n):
    points_lst.append(tuple(map(int, input().split())))
points_set = set(points_lst)
x0, y0 = points_lst[0]
ans = [(x0 + 1, y0 + 1), (x0 + 1, y0), (x0, y0 + 1)]
for i in range(n):
    for j in range(n):
        if i != j:
            x1, y1 = points_lst[i]
            x2, y2 = points_lst[j]
            dx = x2 - x1
            dy = y2 - y1
            x3 = x1 + dy
            y3 = y1 - dx
            x4 = x3 + dx
            y4 = y3 + dy
            if (x3, y3) in points_set and (x4, y4) in points_set:
                ans = []
            if len(ans) > 1 and (x3, y3) in points_set:
                ans = [(x4, y4)]
            if len(ans) > 1 and (x4, y4) in points_set:
                ans = [(x3, y3)]
            if len(ans) > 2:
                ans = [(x3, y3), (x4, y4)]
print(len(ans))
for now in ans:
    print(*now)
