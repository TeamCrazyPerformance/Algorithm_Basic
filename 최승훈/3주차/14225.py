input()
a = 0
# map 함수(분리된 문자열 -> 정수), sorted() 함수 -> list로 반환
for i in sorted(map(int, input().split())):
    # if 문 성립 안 할 시 a까지 합 만들 수 있음 -> a + 1 만들 수 있나 확인!!
    if a + 1 < i:
        break
    a += i
print(a + 1)
