P = [0 for _ in range(101)]
P[1] = 1
P[2] = 1
P[3] = 1

for i in range(0,98):
  P[i+3] = P[i] + P[i+1]

t = int(input())
for i in range(t):
  n = int(input())
  print(P[n])
