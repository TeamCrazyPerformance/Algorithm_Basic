n, k = map(int, input().split())
wheel = ['?'] * n
for i in range(k):
    rotations = input().split()
    count = int(rotations[0]) % n
    alpha = str(rotations[1])
    # 리스트를 슬라이싱 한 후에 앞뒤 순서를 바꿔 다시 붙임
    wheel = wheel[-count:] + wheel[:-count]
    # 움직인 후에 화살표가 가리키는 자리가 '?'일 때
    if wheel[0] == "?":
        # 입력된 문자가 이미 다른 자리에 존재하는 경우, 바퀴 존재하지 않음
        if alpha in wheel:
            print("!")
            break
        wheel[0] = alpha
    # 화살표가 가리키는 자리가 현재 문자와 같은 경우 pass
    elif wheel[0] == alpha:
        continue
    # 화살표가 가리키는 자리에 현재 문자와 다른 문자가 존재, 자리가 겹치므로 바퀴 성립 X
    else:
        print("!")
        break
# 반복문이 break 되지 않고 정상 종료 되었을 때
else:
    print("".join(wheel))
