import sys

N, M = map(int, sys.stdin.readline().split())
nums = []
for i in range(N):
    num = list(map(int, sys.stdin.readline().split()))
    nums.append(num)

sums = [[0] * (N + 1) for _ in range(N + 1)]

# 2차원 누적합 구하기
for i in range(1, N + 1):
    for j in range(1, N + 1):
        sums[i][j] = sums[i][j - 1] + sums[i - 1][j] - sums[i - 1][j - 1] + nums[i - 1][j - 1]

# (x1, y1) -> (x2, y2)
for _ in range(M):
    x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
    result = sums[x2][y2] - sums[x2][y1 - 1] - sums[x1 - 1][y2] + sums[x1 - 1][y1 - 1]
    print(result)
