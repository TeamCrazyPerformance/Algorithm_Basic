#include<stdio.h>

int main() {
	long long A, B, C;
	scanf("%lld %lld %lld", &A, &B, &C);
	long long result = 1;
	while (B > 0) {
		if (B % 2 == 1) {
			result = (result * A) % C;
		}
		A = ((A % C) * (A % C)) % C;
		B /= 2;
	}
	printf("%lld", result);
	return 0;
}
