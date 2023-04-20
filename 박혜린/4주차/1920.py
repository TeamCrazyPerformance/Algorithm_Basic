import sys

N = int(sys.stdin.readline())
N_integers = list(map(int,sys.stdin.readline().split()))
M = int(sys.stdin.readline())
M_integers = list(map(int,sys.stdin.readline().split()))


# 방법 1 : 야매
# for number in m_integers:
#   if number in n_integers:
#     print(1) 
#   else:
#     print(0)

# 이분탐색 m_integers에 있는 원소 하나하나가 n_integer 탐색
N_integers.sort()

for n in M_integers:
  f_idx = 0
  l_idx = N-1
  IsExist = False
  
  while f_idx <= l_idx:
    mid = (f_idx + l_idx) // 2
    
    if n == N_integers[mid]:
      IsExist = True
      break
    
    elif n <= N_integers[mid]:
      l_idx = mid-1
      
    else:
      f_idx = mid+1
    
    
  print(1) if IsExist else print(0)
