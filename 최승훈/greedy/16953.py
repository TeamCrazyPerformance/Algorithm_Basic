import sys

a, b = map(int, sys.stdin.readline().split())
count = 1

while b != a:
    temp = b
    if b % 10 == 1:
        b //= 10
    elif b % 2 == 0:
        b //= 2
    # b == a 만족 못하고 b가 0이 되는 경우 + b가 3, 5, 7, 9로 끝나서 그대로인 경우
    if temp == b:
        print(-1)
        break
    count += 1
# 반복문이 정상적으로 종료된다면
else:
    print(count)
