import sys
n, k = map(int, sys.stdin.readline().split())
student = [0]*n # 등수별 이름 길이 
cartridge = [0] * 20 # 현재 인덱스를 기준으로 등수가 3 이상 차이나지 않는 친구들의 이름 길이별 리스트
pairs = 0

for i in range(n):
  student[i] = len(sys.stdin.readline().rstrip())
  if i > k : # 현재 갖고 있는 학생 수가 k보다 클 때,
    cartridge[student[i-k-1]] -= 1 # 등수가 3 이상 차이나는 학생을 cartridge list에서 제거
  pairs += cartridge[student[i]] # cartridge list에서 이름의 길이가 같은 친구를 더함
  cartridge[student[i]] += 1

print(pairs)  
