n, k = map(int, input().split())
origin = [i + 1 for i in range(n)]
answer = []
index = 0

for i in range(n):
    index += (k - 1)
    if index >= len(origin):
        index %= len(origin)
    answer.append(str(origin[index]))
    origin.pop(index)
print("<",', '.join(answer),">", sep="")
