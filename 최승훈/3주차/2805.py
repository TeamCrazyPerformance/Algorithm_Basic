import sys

N, M = map(int, sys.stdin.readline().split())
tree = list(map(int, sys.stdin.readline().split()))

# 이분 탐색 검색 범위 설정
start, end = 1, max(tree)

while start <= end:
    mid = (start + end) // 2

    height = 0  # 나무 높이의 총합
    for i in tree:
        if i >= mid:
            height += i - mid
            
    # 높이를 이분 탐색
    if height >= M:
        start = mid + 1
    else:
        end = mid - 1

print(end)
