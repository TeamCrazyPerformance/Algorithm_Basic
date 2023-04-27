import sys

N = int(sys.stdin.readline())

time = [[0]*2 for _ in range(N)]
for i in range(N):
    st, ed = map(int, sys.stdin.readline().split())
    time[i][0] = st
    time[i][1] = ed
    
# x[1] 기준으로 오름차순 정렬 / x[0] 기준으로 내림차순 정렬(시작 시간과 끝나는 시간 같은 경우 고려)
time.sort(key=lambda x: (x[1], x[0]))

cnt = 1
end_time = time[0][1]
for i in range(1, N):
    if time[i][0] >= end_time:
        cnt += 1
        end_time = time[i][1]

print(cnt)
