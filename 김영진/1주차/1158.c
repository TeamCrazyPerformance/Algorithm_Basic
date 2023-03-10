#include<stdio.h>
#include<stdlib.h>
#define empty 0

typedef struct node {
	int value;
	struct node* next;
}node;

node* head;

void init() {
	head = NULL;
}

void insert_node(int data) {
	node* ptr;
	node* newnode = (node*)malloc(sizeof(node));
	newnode->next = NULL;
	newnode->value = data;
	if (head == NULL) {
		head = newnode;
	}
	else {
		if (head->value > newnode->value) {
			newnode->next = head;
			head = newnode;
			return;
		}
		for (ptr = head; ptr->next; ptr = ptr->next) {
			if (ptr->value < newnode->value && newnode->value < ptr->next->value) {
				newnode->next = ptr->next;
				ptr->next = newnode;
				return;
			}
		}
		ptr->next = newnode;
	}
}

int delete_node(int* arr, int n, int k) {
	node* cur, * prev, *ptr;
	cur = prev = head;

	if (head == NULL) {
		printf("list is empty\n");
		return -1;
	}
	else if (k == 1) {
		for (int s = 0; s < n; s++) {
			*(arr + s) = cur->value;
			cur = cur->next;
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k - 1; j++) {
				if (cur->next == empty) {
					cur = head;
					if (j == k - 2) {
						*(arr + i) = cur->value;
						head = cur->next;
						ptr = cur;
						if (cur->next == empty) {
							cur = head;
						}
						else {
							cur = cur->next;
						}
						ptr->next = NULL;
						free(ptr);
					}
				}
				else {
					cur = cur->next;
					if (j == k - 2){
						*(arr + i) = cur->value;
						prev->next = cur->next;
						ptr = cur;
						if (cur->next == empty) {
							cur = head;
						}
						else {
							cur = cur->next;
						}
						ptr->next = NULL;
						free(ptr);
					}
				}
				prev = cur;
			}
		}
		return 1;
	}
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	init();
	for (int i = 0; i < n; i++) {
		insert_node(i + 1);
	}
	int arr[5000];

	delete_node(arr, n, k);

	printf("<");
	for (int x = 0; x < n - 1; x++) {
		printf("%d, ", arr[x]);
	}
	printf("%d>", arr[n - 1]);

	return 0;
}
