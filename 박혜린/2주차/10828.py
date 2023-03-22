import sys

stack = []
n = int(sys.stdin.readline())

for i in range(n):
  INPUT = sys.stdin.readline().split()
  
  if INPUT[0] == "push":
    stack.append(INPUT[1])
    
  elif INPUT[0] == "pop":
    if len(stack) == 0 :
      print(-1)
    else:
      print(stack.pop())
      
  elif INPUT[0] == "size":
    print(len(stack))    
      
  elif INPUT[0] == "empty":
    if len(stack) == 0:
      print(1)
    else:
      print(0)
  
  elif INPUT[0] == "top":
    if len(stack) == 0 :
      print(-1)
    else :
      print(stack[-1])
