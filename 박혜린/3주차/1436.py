n = int(input()) # n은 10,000보다 작거나 같은 자연수. string으로 받는다
count = 0
num = 0

while count != n: 
  num += 1
  if '666' in str(num): # n 번째 count가 나오면 그 수를 출력
    count += 1
  
print(num)
