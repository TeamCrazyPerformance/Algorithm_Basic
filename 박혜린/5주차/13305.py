import sys

N = int(sys.stdin.readline())
city_length = list(map(int,sys.stdin.readline().split()))
oil_cost = list(map(int,sys.stdin.readline().split()))
oil_cost.pop()

# 남은거리, 소요 비용
distance = sum(city_length) 
cost = 0

for i in range(N-1): # i : 현재 도시
  IsExpensive = []
  for j in range(i+1, N-1): # j : 이후 도시
    if oil_cost[i] <= oil_cost[j]:
      IsExpensive.append(False)
    else:
      IsExpensive.append(True)
  if IsExpensive.count(True) >= 1 :
    idx = IsExpensive.index(True) + 1
    dist = sum(city_length[i:idx])
    cost += dist * oil_cost[i]
    distance -= dist
  else:
    cost += distance * oil_cost[i]
    break  
print(cost)

# for i in range(N-1): # i : 현재 도시
#   if oil_cost[i] == min(oil_cost):
#     cost = oil_cost[i] * distance
#     break
#   else:
#     IsExpensive = []
#     for j in range(i, N-1): # j : 이후 도시
#       if oil_cost[i] < oil_cost[j]:
#         IsExpensive.append(True)
#       else:
#         IsExpensive.append(False)
#     if IsExpensive.count(True) >= 1 :
      
