import sys

n = int(sys.stdin.readline())
dp = [x for x in range(n + 1)]
# dp[0] = 0
# dp[1] = 1
# dp[2] = 2
# dp[3] = 3
# dp[4] = 1
# dp[5] = 2
# dp[6] = 3
# dp[7] = 4
for i in range(1, n + 1):
    for j in range(1, i):
        if j * j > i:
            break
        if dp[i] > dp[i - j * j] + 1:
            dp[i] = dp[i - j * j] + 1
print(dp[n])
