import sys
N = int(sys.stdin.readline())
count = 0

# 재귀함수
def h(n, from_pos, to_pos, aux_pos):
  if n == 1:
    print(from_pos, to_pos)
    return
  
  h(n-1, from_pos, aux_pos, to_pos)
  print(from_pos, to_pos)
  h(n-1, aux_pos, to_pos, from_pos)
  
print(2**N-1)
if N <= 20 :
  h(N,1,3,2)
