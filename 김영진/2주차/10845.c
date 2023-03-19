#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
	int value;
	struct node* next;
}node;

typedef struct queue {
	node* front;
	node* rear;
	int count;
}queue;

void init_queue(queue* queue) {
	queue->front = NULL;
	queue->rear = NULL;
	queue->count = 0;
}

int isEmpty(queue* queue) {
	return queue->count == 0;
}

void enqueue(queue* queue, int data) {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->value = data;
	newnode->next = NULL;
	if (isEmpty(queue)) {
		queue->front = newnode;
	}
	else {
		queue->rear->next = newnode;
	}
	queue->rear = newnode;
	queue->count++;
}

void dequeue(queue* queue) {
	int data;
	node* ptr;
	if (isEmpty(queue)) {
		printf("-1\n");
		return;
	}
	ptr = queue->front;
	data = ptr->value;
	queue->front = ptr->next;
	free(ptr);
	queue->count--;
	printf("%d\n", data);
	return;
}

int print_data(queue* queue, int d) {
	if (d) {	// front
		printf("%d\n", queue->front->value);
	}
	else {		// back
		printf("%d\n", queue->rear->value);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	queue queue;
	init_queue(&queue);
	for (int i = 0; i < n; i++) {
		char str[6];
		scanf("%s", str);
		if (strcmp(str, "push") == 0) {
			int a;
			scanf("%d", &a);
			enqueue(&queue, a);
		}
		else if (strcmp(str, "pop") == 0) {
			dequeue(&queue);
		}
		else if (strcmp(str, "size") == 0) {
			printf("%d\n", (&queue)->count);
		}
		else if (strcmp(str, "empty") == 0) {
			if (isEmpty(&queue)) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (strcmp(str, "front") == 0) {	// 가장 앞에 있는 정수 출력
			if (isEmpty(&queue)) {
				printf("-1\n");
			}
			else {
				print_data(&queue, 1);
			}
		}
		else {	// str == back				           가장 뒤에 있는 정수 출력 
			if (isEmpty(&queue)) {
				printf("-1\n");
			}
			else {
				print_data(&queue, 0);
			}
		}
	}
	return 0;
}
