n, k = map(int, input().split())
wheel = ['?'] * n
idx = 0

for i in range(k):
  s, char = input().split()
  s = int(s)
  idx += s
  if idx >= n:
    idx %= n
  
  if wheel[idx] != '?' and wheel[idx] != char:
    print('!')
    break
  elif wheel[idx] == "?" and char in wheel: # wheel에 한 칸에 들어있는 문자가 다른 칸에도 존재
    print('!')
    break
  
  wheel[idx] = char

  if i == k-1:
    wheel = wheel[::-1]
    sort_index = wheel.index(char)
    wheel = wheel[sort_index:] + wheel[:sort_index]
    print("".join(wheel))
