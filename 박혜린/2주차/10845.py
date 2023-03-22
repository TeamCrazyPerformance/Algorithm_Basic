import sys

queue = []
n = int(sys.stdin.readline())

for i in range(n):
  INPUT = sys.stdin.readline().split()
  
  if INPUT[0] == "push":
    queue.append(INPUT[1])
    
  elif INPUT[0] == "pop":
    if len(queue) == 0 :
      print(-1)
    else:
      print(queue.pop(0))
      
  elif INPUT[0] == "size":
    print(len(queue))    
      
  elif INPUT[0] == "empty":
    if len(queue) == 0:
      print(1)
    else:
      print(0)
  
  elif INPUT[0] == "front":
    if len(queue) == 0 :
      print(-1)
    else :
      print(queue[0])
      
  elif INPUT[0] == "back":
    if len(queue) == 0 :
      print(-1)
    else :
      print(queue[-1])
