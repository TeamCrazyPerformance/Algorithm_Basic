# import sys
# n, p = map(int, sys.stdin.readline().split())
# fingerboard = [[0 for j in range(p)] for i in range(6)]
# stack = [0]*6 # 줄마다 쌓인 횟수
# moves = 0

# for _ in range(n):
#   line, fret = map(int, sys.stdin.readline().split())
  
#   if fingerboard[line-1][fret-1] == 0 :
#     fingerboard[line-1][fret-1] = 1
#     moves += 1 
#     stack[line-1] += 1

#   if stack[line-1] > 1:
#     pos = [i for i in range(len(fingerboard[line-1])) if fingerboard[line-1][i] == 1]
#     for i in range(stack[line-1]):
#       if pos[-1] > fret-1:
#         fingerboard[line-1][pos[-1]] = 0
#         pos.pop()
#         moves += 1
#         stack[line-1] -= 1
    
# print(moves)

import sys

n, p = map(int, sys.stdin.readline().split())
fingerboard = [[0] for i in range(6)]
moves = 0

for i in range(n):
    line, fret = map(int, sys.stdin.readline().split())

    while fingerboard[line-1][-1] > fret:
        fingerboard[line-1].pop()
        moves += 1
    if fingerboard[line-1][-1] == fret:
        continue

    fingerboard[line-1].append(fret)
    moves += 1

print(moves)
