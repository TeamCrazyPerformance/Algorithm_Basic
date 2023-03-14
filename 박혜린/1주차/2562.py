i = 9
li = []
max_n = 0

while i > 0:
  n = int(input())
  if 0 < n < 100:
    li.append(n)
    i -=1
  else:
    print("Input a number between 0 and 100")

for i in li:
  if i > max_n:
    max_n = i

# print(max(li))
# print(li.index(max(li))+1)

print(max_n)
print(li.index(max_n)+1)
