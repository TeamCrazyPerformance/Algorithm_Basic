#include<stdio.h>
#include<string.h>
#define stack_size 10000

int stack[stack_size];
int top = -1;

int isFull() {
	if (top >= stack_size - 1) {
		return 1;
	}
	return 0;
}

int empty() {
	if (top == -1) {
		return 1;
	}
	return 0;
}

void push(int data) {
	if (!isFull()) {
		top++;
		stack[top] = data;
	}
}
int pop() {
	if (empty()) {
		printf("-1\n");
	}
	else {
		printf("%d\n", stack[top--]);
	}
}
void size() {
	printf("%d\n", top + 1);
}

void s_top() {
	if (empty()) {
		printf("-1\n");
	}
	else {
		printf("%d\n", stack[top]);
	}
}


int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int data;
		char str[6];
		scanf("%s", str);
		if (strcmp(str, "push") == 0) {
			scanf("%d", &data);
			push(data);
		}
		else if (strcmp(str, "pop") == 0) {
			pop();
		}
		else if (strcmp(str, "size") == 0) {
			size();
		}
		else if (strcmp(str, "empty") == 0) {
			printf("%d\n", empty());
		}
		else {
			s_top();
		}
	}

	return 0;

}
