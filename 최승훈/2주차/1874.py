n = int(input())
stack = []
result = []
count = 1

for i in range(1, n+1):
    num = int(input())
    # num까지 push
    while count <= num:
        stack.append(count)
        result.append('+')
        count += 1
    if stack[-1] == num:
        stack.pop()
        result.append('-')
    else:
        print('NO')
        exit(0) # 프로그램 종료

print('\n'.join(result))
