import sys

n = int(sys.stdin.readline())
d = [0] * (n + 1)
# 세 연산 모두 시도!!
# d[0] = 0
# d[1] = 0
# d[2] = 1
# d[3] = 1
# d[4] = 2
# d[5] = 3
for i in range(2, n + 1):
    d[i] = d[i - 1] + 1
    if i % 3 == 0:
        d[i] = min(d[i], d[i // 3] + 1)
    if i % 2 == 0:
        d[i] = min(d[i], d[i // 2] + 1)
print(d[n])
