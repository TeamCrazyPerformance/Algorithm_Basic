n, m = map(int, input().split())
maps = [[] for _ in range(n)]

for i in range(n):
    data = list(map(int, input().split()))
    maps[i].extend(data) # append 그대로 들어감 extend 리스트 안의 원소가 들어감 ㅎㅎ

for _ in range(int(input())):
    a, b, c, d = map(int, input().split())
    total = 0
    for i in range(a - 1, c):
        for j in range(b - 1, d):
            total += maps[i][j]

    print(total)
