import sys

N = int(sys.stdin.readline())

stair = [[0] * 10 for _ in range(N + 1)]
MOD = 1000000000
for i in range(1, 10):
    stair[1][i] = 1
for i in range(2, N + 1):
    for j in range(10):
        # 0일 떄 가능한 계단 수는 1
        if j == 0:
            stair[i][j] = stair[i - 1][j + 1]
        # 9일 때 가능한 계단 수는 8
        elif j == 9:
            stair[i][j] = stair[i - 1][j - 1]
        else:
            stair[i][j] = stair[i - 1][j - 1] + stair[i - 1][j + 1]

print(sum(stair[N]) % MOD)
