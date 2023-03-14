# 시간 초과 코드 1
# n, m = map(int, input().split())
# arr = [list((map(int,input().split()))) for i in range(n)]
# k = int(input())
# while k > 0 :
#     SUM = 0
#     i, j, x, y = map(int, input().split())
#     for r in range(i, x+1):
#         for c in range(j, y+1):
#             SUM += arr[r-1][c-1]
#     k -= 1
#     print(SUM)


# dynamic programming
n, m = map(int, input().split())
arr = [list(map(int, input().split())) for i in range(n)]
k = int(input())
dp = [[0] * m for _ in range(n)] # 원소가 모두 0이고, arr와 동일한 크기의 2차원 배열 생성

for i in range(n):
    for j in range(m):
        if i == 0 and j == 0:
            dp[i][j] = arr[i][j]
        elif i == 0 and j != 0:
            dp[0][j] = dp[0][j-1] + arr[0][j]
        elif i != 0 and j == 0:
            dp[i][0] = dp[i-1][0] + arr[i][0]
        elif i > 0 and j > 0:
            dp[i][j] = -dp[i-1][j-1] + dp[i-1][j] + dp[i][j-1] + arr[i][j] # dp[i-1][j-1] 중복

for _ in range(k):
    i, j, x, y = map(int, input().split())
    if i == 1 and j == 1:
        print(dp[x-1][y-1])
    elif i == 1 and j != 1:
        print(dp[x-1][y-1] - dp[x-1][j-2])
    elif i != 1 and j == 1:
        print(dp[x-1][y-1] - dp[i-2][y-1])
    elif i != 1 and j != 1:
        print(dp[x-1][y-1] - dp[i-2][y-1] - dp[x-1][j-2] + dp[i-2][j-2]) # dp[i-2][j-2] 중복
