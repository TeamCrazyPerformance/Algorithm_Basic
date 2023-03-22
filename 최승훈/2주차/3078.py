from sys import stdin
from collections import deque
N, K = map(int, stdin.readline().split())
grade = [0] * 21
student = deque()
count = 0
for _ in range(N):
    # 오른쪽 개행 문자 제거
    a = len(stdin.readline().rstrip())
    student.append(a)
    grade[a] += 1
    if len(student) > K + 1:
        old = student.popleft()
        grade[old] -= 1
    # n번 친구와 쌍인 친구 = grade[a] - 1
    count += (grade[a] - 1)
print(count)
