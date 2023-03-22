# import sys
# n = int(sys.stdin.readline())
# queue = [i+1 for i in range(n)] 

# while len(queue) != 1:
#   queue.pop(0)
#   queue = queue[1:] + [queue[0]]

# print(queue[0])

import sys
from collections import deque
n = int(sys.stdin.readline())
deque = deque([i+1 for i in range(n)])

while len(deque) != 1:
  deque.popleft()
  a = deque.popleft()
  deque.append(a)
  
print(deque[0])
