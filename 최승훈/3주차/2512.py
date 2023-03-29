import sys

N = int(sys.stdin.readline())
requests = list(map(int, sys.stdin.readline().split()))
M = int(sys.stdin.readline())
# 시작 점, 끝 점
start, end = 0, max(requests)

while start <= end:
    mid = (start+end) // 2
    # 총 지출 양
    total = 0
    for i in requests:
        if i > mid:
            total += mid
        else:
            total += i
    # 지출 양이 예산 보다 작으면
    if total <= M: 
        start = mid + 1
    # 지출 양이 예산 보다 크면
    else: 
        end = mid - 1
print(end)
