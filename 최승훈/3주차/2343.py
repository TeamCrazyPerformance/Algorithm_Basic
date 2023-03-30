import sys

n, m = map(int, sys.stdin.readline().split())
data = list(map(int, sys.stdin.readline().split()))

# 순서를 유지해야 하므로 정렬을 사용하면 안된다.
# 모두 담을 수 있어야 하므로 start = max(data)
# 블루레이의 크기 중 최소이므로 sum(data)보다는 작다.
num = sum(data)
start = max(data)
end = num
result = 1e9 + 7

while start <= end:
    # mid는 블루레이 크기(size)
    mid = (start + end) // 2
    # count는 블루레이 개수 , length는 블루레이 길이
    count, length = 1, 0
    for i in range(len(data)):
        # length는 지금까지 블루레이 크기의 합, data[i] 다음 블루레이 크기
        if length + data[i] <= mid:
            length += data[i]
        else:
            # mid 보다 커지면 현재 data[i] -> length 개수 1개 늘려준다.
            length = data[i]
            count += 1
    # 개수가 m보다 작거나 같으면 이분 탐색 실행
    if count <= m:
        end = mid - 1
        # mid 중에 제일 작은 값 저장
        result = min(result, mid)
    else:
        start = mid + 1
print(result)

