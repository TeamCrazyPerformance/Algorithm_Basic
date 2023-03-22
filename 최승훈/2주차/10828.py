import sys

N = int(sys.stdin.readline())

stack = []

for _ in range(N):
    # stdin: input stream / readline(): reads a line / .split() : splits -> Strings
    word = sys.stdin.readline().split()
    command = word[0]
    
    # command: push
    if command == "push":
        value = word[1]
        stack.append(value)

    # command: pop
    elif command == "pop":
        if len(stack) == 0:
            print(-1)
        else:
            print(stack.pop())

    # command: size
    elif command == "size":
        print(len(stack))

    # command: empty
    elif command == "empty":
        if len(stack) == 0:
            print(1)
        else:
            print(0)

    # command: top
    elif command == "top":
        if len(stack) == 0:
            print(-1)
        else:
            print(stack[-1])
