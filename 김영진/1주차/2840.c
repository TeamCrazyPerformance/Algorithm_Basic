#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	char value;
	struct node* next;
	struct node* prev;
}node;

node* head;
node* rhead;

void init() {
	head = NULL;
	rhead = NULL;
}

void insert_node(int data, int data2, char* str, int* wheel) {
	node* ptr;
	node* fill;
	ptr = head;
	int n = 0, two = 0, thr = 0;
	char a;
	for (int k = 0; k < data2; k++) {
		int num;
		scanf("%d %c", &num, &a);
		thr += num;
		for (int i = 0; i < num; i++) {
			if (n < data) {
				node* newnode = (node*)malloc(sizeof(node));
				if (i == num - 1) {
					newnode->value = a;
				}
				else {
					newnode->value = '?';
				}
				newnode->next = NULL;
				newnode->prev = NULL;
				if (head == NULL) {
					head = newnode;
					ptr = newnode;
					rhead = newnode;
				}
				else {
					for (ptr = head; ptr->next; ptr = ptr->next) {

					}
					ptr->next = newnode;
					newnode->prev = ptr;
					ptr = ptr->next;
					rhead = newnode;
				}
				n++;
			}
			else {
				if (ptr->next == NULL) {
					ptr = head;
				}
				else {
					ptr = ptr->next;
				}
				if (i == num - 1) {
					if (ptr->value == '?') {
						ptr->value = a;
					}
					else if (ptr->value == a) {
						two += 1;
					}
					else {
						*wheel = -1;
					}
				}
			}
		}
		int count = 0;
		for (node* tmp = head; tmp; tmp = tmp->next) {
			if (tmp->value == a) {
				count += 1;
			}
			if (count == 2) {
				*(wheel) = -1;
				return;
			}
		}
	}
	*str = ptr->value;
	if (data > thr) {
		fill = rhead;
		for (int h = 0; h < data - thr - two; h++) {
			node* newnode = (node*)malloc(sizeof(node));
			newnode->value = '?';
			newnode->prev = fill;
			newnode->next = NULL;
			fill->next = newnode;
			fill = fill->next;
			rhead = fill;
		}
	}
}

void print_list(char start) {
	node* ptr;
	ptr = head;
	while (ptr->value != start) {
		ptr = ptr->next;
	}
	for (; ptr; ptr = ptr->prev) {
		printf("%c", ptr->value);
	}
	ptr = rhead;
	while (ptr->value != start) {
		printf("%c", ptr->value);
		ptr = ptr->prev;
	}
}

int main() {
	int n, k, w;
	char* str;
	char s = '0';
	int* wheel;
	w = 1;
	str = &s;
	wheel = &w;
	scanf("%d %d", &n, &k);
	init();
	insert_node(n, k, str, wheel);
	if (w == -1) {
		printf("!");
	}
	else {
		print_list(*str);
	}
	return 0;
}
