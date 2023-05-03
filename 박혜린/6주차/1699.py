N = int(input())
cnt = 0

while N != 0 :
  cnt += 1
  N -= int(N ** 0.5) ** 2

print(cnt)
