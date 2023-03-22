import sys

N = int(sys.stdin.readline())

# 1, 2, 3, 4, 5, 6
plist = [i + 1 for i in range(N)]

while len(plist) > 1:
    if len(plist) % 2:
        # top = [6]
        top = [plist[-1]]
        # top = [6, 4]
        top.extend(plist[1::2])
        plist = top
    else:
        plist = plist[1::2]

print(plist[0])
