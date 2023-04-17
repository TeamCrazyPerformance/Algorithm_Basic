#include<stdio.h>
#include<stdlib.h>

int compare(int* x, int* y) {
	if (*x > *y) {
		return 1;
	}
	else if (*x < *y) {
		return -1;
	}
	else {
		return 0;
	}
}

int a[100000];

int main() {
	int n;
	int a_0 = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {	// A[1], A[2], ...,A[n]
		scanf("%d", a + i);
		if (*(a + i) == 0) {
			a_0++;
		}
	}
	qsort(a, 100000, sizeof(int), compare);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		if (x == 0) {
			if (a_0 == 1) {
				printf("1\n");
				continue;
			}
			printf("0\n");
			continue;
		}
		int left = 0;
		int right = 99999;
		int mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (x < a[mid]) {
				right = mid - 1;
			}
			else if (a[mid] < x) {
				left = mid + 1;
			}
			else {
				printf("1\n");
				break;
			}
		}
		if (a[mid] != x) {
			printf("0\n");
		}
	}
	return 0;
}
