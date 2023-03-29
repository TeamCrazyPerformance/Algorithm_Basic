import sys
N, M, B = map(int, input().split())
block = []
for _ in range(N):
    block.append([int(x) for x in sys.stdin.readline().rstrip().split()])

# 곱해도 (long long)의 범위 더해도 (int)의 범위를 넘지 않는 소수
answer = int(1e9 + 7)
height = 0

# 0부터 256까지
for i in range(257):
    build = 0
    remove = 0
    # N줄(세로 길이)
    for x in range(N):
        # M개의 땅(가로 길이)
        for y in range(M):
            # i(맞추려는 높이)보다 높다면
            if block[x][y] > i:
                remove += block[x][y] - i
            else:
                build += i - block[x][y]
    # 짓는데 쓴 블록 <= 제거한 블록 + 가지고 있는 블록
    if build <= remove + B:
        time = remove * 2 + build
        # 최소 시간 -> 최소 시간 여러 개일 경우 땅의 높이가 가장 높은 것
        if time <= answer:
            # 최저 시간
            answer = time
            # 층수
            height = i

print(answer, height)
