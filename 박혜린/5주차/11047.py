import sys

N, K = map(int, sys.stdin.readline().split())
list_A_i = [] 
num = 0

for i in range(N):
  list_A_i.append(int(sys.stdin.readline()))

list_A_i.sort(reverse=True)
for A_i in list_A_i:
  if K >= A_i:
    num += K // A_i
    K %= A_i
    if K == 0:
      break
print(num)
