a1, a0 = map(int, input().split())
c = int(input())
n0 = int(input())
if a1 > c:
    print(0)
elif a1 == c:
    if a0 > 0:
        print(0)
    else:
        print(1)
else:
    n = c - a1
    x = a0 / n
    if x > n0:
        print(0)
    else:
        print(1)
