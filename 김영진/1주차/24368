#include<stdio.h>

int main() {
	double a2, a1, a0, c, n0;
	scanf("%lf %lf %lf", &a2, &a1, &a0);
	scanf("%lf", &c);
	scanf("%lf", &n0);
	int result = 0;
	if (a2 - c > 0) {
		result = 0;
	}
	else if (a2 == c) {
		if (a1 == 0 && a0 <= 0) {
			result = 1;
		}
		else if (a1 < 0 && a1 * n0 + a0 <= 0) {
			result = 1;
		}
		else {
			result = 0;
		}
	}
	else {
		if (n0 <= -a1 / (2 * (a2 - c))) {
			if (a1 * a1 / (4 * (a2 - c)) - a1 * a1 / (2 * (a2 - c)) + a0 <= 0) {
				result = 1;
			}
			else {
				result = 0;
			}
		}
		else {
			if ((a2 - c) * n0 * n0 + a1 * n0 + a0 <= 0) {
				result = 1;
			}
			else {
				result = 0;
			}
		}
	}
	printf("%d", result);
	return 0;
}

// 모든 n >= n0 에 대하여 a2*n*n + a1*n + a0 <= c * n*n 인 c 와 n0 가 존재함
// (a2 - c)*n*n + a1*n + a0 <= 0
// a2 - c > 0 X
// a2 - c = 0  ->  a1 = 0 && a0 <= 0, a1 < 0 && a1*n0 + a0 <= 0
// a2 - c < 0
// ->  n = -a1/2*a2 일 때 최대갑이다.
// ->  n0 <= -a1/(2*(a2 - c)) -> a1*a1/(4*(a2 - c)) - a1*a1/(2*(a2 - c)) + a0 <= 0
//     n0 > -a1/(2*(a2 - c))  -> (a2 - c)*n0*n0 + a1*n0 + a0 <= 0
