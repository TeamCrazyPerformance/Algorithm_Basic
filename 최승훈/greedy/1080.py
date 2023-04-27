import sys

n, m = map(int, sys.stdin.readline().split())
count = 0

# 행렬 A B 입력 받기
matrixA = [list(map(int, sys.stdin.readline().rstrip())) for _ in range(n)]
matrixB = [list(map(int, sys.stdin.readline().rstrip())) for _ in range(n)]


def convert_matrix(row, col, matrix):
    # 3x3 행렬 변환 함수 생성
    for x in range(row, row + 3):
        for y in range(col, col + 3):
            matrix[x][y] = 1 - matrix[x][y]


for i in range(n - 2):
    for j in range(m - 2):
        # 다른 원소 있으면 뒤집기
        if matrixA[i][j] != matrixB[i][j]:
            convert_matrix(i, j, matrixA)
            count += 1

# 변환할 행렬과 정답 행렬 비교 검증
flag = False
for i in range(n):
    for j in range(m):
        # 다르면 -1
        if matrixA[i][j] != matrixB[i][j]:
            print(-1)
            flag = True
            break
    if flag:
        break
else:
    print(count)
