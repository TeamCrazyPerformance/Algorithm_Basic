import sys

N, K = map(int, sys.stdin.readline().split())
coins = [int(sys.stdin.readline()) for _ in range(N)]

# 모두 int의 최대값으로 초기화
table = [0] + [float('inf')] * K

for i in range(1, K + 1):
    for j in range(N):
        if coins[j] <= i:
            sub = table[i - coins[j]]
            # sub가 int 최대값이 아니고 sub + 1이 기존 값보다 작을 때 table에 저장
            if sub != float('inf') and sub + 1 < table[i]:
                table[i] = sub + 1
if table[K] == float('inf'):
    print(-1)
else:
    print(table[K])
