import sys
import heapq

N = int(sys.stdin.readline())

leftHeap = []
rightHeap = []
answer = []
for i in range(N):

    num = int(sys.stdin.readline())
    
    # 원소 2개일 시 왼쪽이 가운데
    if len(leftHeap) == len(rightHeap):
        heapq.heappush(leftHeap, (-num, num))
    else:
        heapq.heappush(rightHeap, (num, num))

    if rightHeap and leftHeap[0][1] > rightHeap[0][0]:
        small = heapq.heappop(rightHeap)[0]
        large = heapq.heappop(leftHeap)[1]
        heapq.heappush(leftHeap, (-small, small))
        heapq.heappush(rightHeap, (large, large))

    answer.append(leftHeap[0][1])

for j in answer:
    print(j)
    
