n, k = map(int, input().split())

li = [i+1 for i in range(n)]
seq = []
index = k - 1 

while len(li) > 0:
  if index >= len(li):
    index = index % len(li)
  else:
    seq.append(str(li.pop(index)))
    index += k - 1

print("<", ", ".join(seq), ">", sep='')
