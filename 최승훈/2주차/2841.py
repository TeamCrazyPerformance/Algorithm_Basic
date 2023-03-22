import sys

n, p = map(int, sys.stdin.readline().split())
line = [[0] for _ in range(7)]
cnt = 0


for i in range(n):
    # 줄의 번호, 프렛의 번호
    line_num, fret_num = map(int, sys.stdin.readline().split())

    # 누르고자 하는 fret이 작을 때 손가락 떼기
    while line[line_num][-1] > fret_num:
        line[line_num].pop()
        cnt += 1

    # 이미 누르고 있을 때 continue
    if line[line_num][-1] == fret_num:
        continue

    # 프렛을 누른다.
    line[line_num].append(fret_num)
    cnt += 1

print(cnt)
