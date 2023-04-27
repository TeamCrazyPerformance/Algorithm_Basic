import sys
F = sys.stdin.readline().split("-")
ans = 0

for i in F:
  value = 0
  if i.count("+") >= 1:
    FF = list(map(int, i.split("+")))
    value += sum(FF)
  else:
    FF = int(i)
    value += FF
    
  if i == F[0]: # F의 첫 번째 값은 무조건 양수
    ans += value
  else:
    ans -= value
print(ans)

# import sys
# F = sys.stdin.readline().split("-")
# ans = 0

# for i in F:
#   value = int(eval(i))
#   if i == F[0]:
#     ans += value
#   else:
#     ans -= value
# print(ans)
