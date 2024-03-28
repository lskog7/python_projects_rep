def main():
    lst = ['' for _ in range(500)]
    cnt = 0
    while True:
        str = input()
        if not str:
            break
        lst[cnt] = str
        cnt+=1
    scores = dict()
    goals = dict()
    for i in range(cnt):
        command = lst[i]
        tmp = command.split()
            
main()