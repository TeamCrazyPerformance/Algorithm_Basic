import sys
n = int(sys.stdin.readline())
roads = list(map(int, sys.stdin.readline().split()))
costs = list(map(int, sys.stdin.readline().split()))

res = 0
m = costs[0]
for i in range(n - 1):
    # 현재 주유소 비용과 다음 주유소 비용 비교
    if costs[i] < m:
        m = costs[i]
    res += m * roads[i]

print(res)
