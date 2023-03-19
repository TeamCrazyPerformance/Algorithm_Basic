#include<stdio.h>
#define stack_size 300000

int stack[6][stack_size];
int top[6] = { -1,-1,-1,-1,-1 };
int f = 0;

int isEmpty(int ln) {
	if (top[ln] == -1) {
		return 1;
	}
	return 0;
}

int isFull(int ln) {
	if (top[ln] >= stack_size - 1) {
		return 1;
	}
	return 0;
}

void push(int ln, int pn) {
	if (!isFull(ln)) {
		top[ln]++;
		stack[ln][top[ln]] = pn;
		f += 1;
	}
}

void pop(int ln) {
	if (!isEmpty(ln)) {
		top[ln]--;
		f += 1;
	}
}

int main() {
	int n, p;
	scanf("%d %d", &n, &p);
	for (int i = 0; i < n; i++) {
		int ln, pn;
		scanf("%d %d", &ln, &pn);
		ln--;
		if (top[ln] == -1) {
			push(ln, pn);
		}
		if (stack[ln][top[ln]] == pn) {

		}
		else if (stack[ln][top[ln]] < pn) {
			push(ln, pn);
		}
		else {
			while (stack[ln][top[ln]] > pn) {	// 더 높은 프랫에 있는 손가락 제거
				pop(ln);
			}
			if (stack[ln][top[ln]] == pn) {

			}
			else {
				push(ln, pn);
			}
		}
	}
	printf("%d", f);
	return 0;
}
