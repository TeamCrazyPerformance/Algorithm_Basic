#include<stdio.h>

int wood_h[1000000];

void cut_wood(int start, int h, int end,int n, int m) {
	int count = 0;
	unsigned long wood = 0;
	for (int i = 0; i < n; i++) {
		if (wood_h[i] >= h) {
			wood += wood_h[i] - h;
			count++;
		}
	}
	if (m <= wood && wood < m + count) {
		printf("%d", h);
	}
	else if (wood < m) {
		cut_wood(start, (h - start) / 2, h, n, m);
	}
	else {	// m + count <= wood
		cut_wood(h, h + (end - h) / 2, end, n, m);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int max_wood_h = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &wood_h[i]);
		if (wood_h[i] > max_wood_h) {
			max_wood_h = wood_h[i];
		}
	}
	cut_wood(0, max_wood_h / 2, max_wood_h, n, m);
	return 0;
}
