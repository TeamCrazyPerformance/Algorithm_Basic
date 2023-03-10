#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int arr[300][300];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int k;
	scanf("%d", &k);
	for (int l = 0; l < k; l++) {
		int a, b, c, d;
		int result = 0;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		for (int x = a - 1; x < c; x++) {
			for (int y = b - 1; y < d; y++) {
				result += arr[x][y];
			}
		}
		printf("%d\n", result);
	}
	return 0;
}
