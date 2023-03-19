#include<stdio.h>
#define stack_size 100000

int stack[stack_size];
int top = -1;
int num = 1;

int isEmpty() {
	if (top == -1) {
		return 1;
	}
	return 0;
}

int isFull() {
	if (top >= stack_size - 1) {
		return 1;
	}
	return 0;
}

void push() {
	if (!isFull()) {
		top++;
		stack[top] = num;
		num += 1;
	}
}

void pop() {
	if (!isEmpty()) {
		top--;
	}
}

int main() {
	int n;
	int count[100000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		count[i] = 0;
		scanf("%d", &a);
		if (stack[top] > a) {
			printf("NO");
			return 0;
		}
		while (stack[top] < a) {
			push();
			count[i] += 1;
		}
		if (stack[top == a]) {
			pop();
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < count[i]; j++) {
			printf("+\n");
		}
		printf("-\n");
	}
	return 0;
}
