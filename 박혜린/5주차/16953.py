A, B = map(int,input().split())
result = 1

while(B!=A): # B는 A가 될때까지 반복
    result += 1
    value = B
    if B % 10 == 1:
        B //= 10
    elif B % 2 == 0:
        B //= 2
    
    if value == B:
        print(-1)
        break
else:
    print(result)
