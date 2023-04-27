import sys

minus = sys.stdin.readline().split('-')
res = 0
# ['55', '50 + 40', '30 + 20']
for i in minus[0].split('+'):
    res += int(i)
for i in minus[1:]:
    for j in i.split('+'):
        res -= int(j)
print(res)
