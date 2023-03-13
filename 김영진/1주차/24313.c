#include<stdio.h>

int main() {
	int a1, a0, c, n0;
	int result = 0;
	scanf("%d %d", &a1, &a0);
	scanf("%d\n%d", &c, &n0);
	if (a1 - c > 0) {
		result = 0;
	}
	else if (a1 == c) {
		if (a0 <= 0) {
			result = 1;
		}
		else {
			result = 0;
		}
	}
	else {
		if ((a1 - c) * n0 + a0 <= 0) {
			result = 1;
		}
		else {
			result = 0;
		}
	}
	printf("%d", result);
	return 0;
}

// 모든 n >= n0 에 대하여 a1*n + a0 <= c * n 인 c 와 n0 가 존재함
// (a1 - c)*n + a0 <= 0
// a1 - c > 0 X
// a1 - c == 0  ->  a0 <= 0
// a1 - c < 0   ->  (a1 - c)*n0 + a0 <= 0
