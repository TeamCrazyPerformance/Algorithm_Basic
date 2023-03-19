#include<stdio.h>
#include<stdlib.h>

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
		printf("This queue is empty!\n");
		return;
	}
	ptr = queue->front;
	data = ptr->value;
	queue->front = ptr->next;
	free(ptr);
	queue->count--;
	return;
}

void shuffle(queue* queue) {
	int data;
	data = queue->front->value;
	dequeue(queue);
	enqueue(queue, data);
}

int main() {
	int n;
	queue queue;
	init_queue(&queue);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		enqueue(&queue, i + 1);
	}
	for (int j = 0; j < n - 1; j++) {
		dequeue(&queue);
		shuffle(&queue);
	}
	printf("%d", (&queue)->rear->value);
	return 0;
}
