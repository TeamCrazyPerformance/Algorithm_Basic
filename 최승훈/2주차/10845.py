from sys import stdin

N = int(stdin.readline())
queue = []
for i in range(N):
    A = stdin.readline().split() 
    # sys.stdin.readline().split()
    
    if A[0] == 'push': 
        queue.append(A[1])

    elif A[0] == 'pop': 
        if queue:
            print(queue.pop(0))
        else: 
            print(-1)

    elif A[0] == 'size': 
        print(len(queue))

    elif A[0] == 'empty':
        if len(queue) == 0: 
            print(1)
        else: 
            print(0)
            
    elif A[0] == 'front':
        if len(queue) == 0: 
            print(-1)
        else: 
            print(queue[0])
    
    elif A[0] == 'back':
        if len(queue) == 0: 
            print(-1)
        else: 
            print(queue[-1])
