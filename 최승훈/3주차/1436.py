n = int(input())
cnt = 0
ending = 666
while True:
    if '666' in str(ending):
        cnt += 1
    if cnt == n:
        print(ending)
        break
    ending += 1
