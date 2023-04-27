import sys
n, k = map(int, sys.stdin.readline().split())

coins = [int(sys.stdin.readline()) for _ in range(n)]

# 내림차순
coins.sort(reverse=True)

# 필요한 동전의 개수
result = 0

for coin in coins:
    if k // coin > 0:
        result += k // coin
    k %= coin

print(result)
