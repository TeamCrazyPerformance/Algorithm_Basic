import sys

wave = [0 for i in range(101)]
wave[1] = 1
wave[2] = 1
wave[3] = 1
# 1 1 1 2 2 3 4 5 7 9
for i in range(0, 98):
    wave[i + 3] = wave[i] + wave[i + 1]
t = int(sys.stdin.readline())
for i in range(t):
    n = int(input())
    print(wave[n])
