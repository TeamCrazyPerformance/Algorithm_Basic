#include<stdio.h>
#include<string.h>
int stack[10000] = { 0 };
int siz = 0;

void push(int data) {
	stack[siz] = data;
	siz += 1;
}
int pop() {
	int num;
	if (siz - 1 >= 0) {
		num = stack[siz - 1];
		stack[siz - 1] = 0;
		siz -= 1;
		return num;
	}
	else
		return -1;
}
int size() {
	return siz;
}
int empty()
{
	if (siz != 0)
		return 0;
	else
		return 1;
}
int top()
{
	if (stack[siz - 1] != 0)
		return stack[siz - 1];
	else
		return -1;
}
int main()
{	
	char* push2 = "push";
	char* pop2 = "pop";
	char* size2 = "size";
	char* empty2 = "empty";
	char* top2 = "top";
	int number;
	scanf("%d", &number);
	for(int i = 0; i < number; i++)
	{
		char order[10];
		scanf("%s", order);
		if (!strcmp(push2, order))
		{
			int data1;
			scanf("%d", &data1);
			push(data1);
		}
		if (!strcmp(pop2, order))
		{
			int data2 = pop();
			printf("%d\n", data2);
		}
		if (!strcmp(size2, order))
		{
			int data3 = size();
			printf("%d\n", data3);
		}
		if (!strcmp(empty2, order))
		{
			int data4 = empty();
			printf("%d\n", data4);
		}
		if (!strcmp(top2, order))
		{
			int data5 = top();
			printf("%d\n", data5);
		}
	}
	return 0;
}
