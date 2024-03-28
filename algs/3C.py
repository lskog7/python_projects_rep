n = int(input())
a = list(map(int, input().split()))
cnt ={}
for now in a:
    cnt[now] = cnt.get(now,0) + 1
ans = 0
for key in cnt:
    now = cnt[key] + max(cnt.get(key-1, 0), cnt.get(key+1, 0))
    ans = max(ans,now)
print(n-ans)