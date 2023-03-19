#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long good_friend = 0;
int check_list[19];	// [0] = 2글자, [n] = n + 2글자

typedef struct node {
	char name[21];
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

void enqueue(queue* queue, char* data) {
	node* newnode = (node*)malloc(sizeof(node));
	strcpy(newnode->name, data);
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
	data = ptr->name;
	queue->front = ptr->next;
	free(ptr);
	queue->count--;
	return;
}

void check(queue* queue, int n, int k) {
	node* erase = queue->front;
	node* add = queue->front;
	for (int i = 0; i < k + 1; i++) {
		check_list[strlen(add->name) - 2]++;
		if (i < k) {
			add = add->next;
		}
	}
	for (int i = 0; i < 19; i++) {
		good_friend += (check_list[i] * (check_list[i] - 1)) / 2;
	}
	for (int i = 0; i < n - k - 1; i++) {
		check_list[strlen(erase->name) - 2]--;
		erase = erase->next;
		add = add->next;
		good_friend += check_list[strlen(add->name) - 2];
		check_list[strlen(add->name) - 2]++;
	}
}

int main() {	
	int n, k;	
	scanf("%d %d", &n, &k);	
	queue queue;
	init_queue(&queue);
	for (int i = 0; i < n; i++) {
		char name[21];
		scanf("%s", name);
		enqueue(&queue, name);
	}
	check(&queue, n, k);
	printf("%ld", good_friend);
	return 0;
}
