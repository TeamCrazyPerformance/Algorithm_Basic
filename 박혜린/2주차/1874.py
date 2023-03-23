n = int(input())
stack, ans = [], []
cur = 1
isPossible = True

for i in range(n):
  num = int(input())
  while cur <= num: # push
    stack.append(cur)
    ans.append('+')
    cur += 1
  if stack[-1] == num: # pop
    stack.pop()
    ans.append('-')
  else:
    isPossible = False

if isPossible :
  for i in ans:
    print(i)
else:
  print('NO')
