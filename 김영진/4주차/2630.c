#include<stdio.h>

int white = 0;
int blue = 0;

int arr[128][128];

void cut(int x, int y, int n) {
	int check = 0;
	if (n != 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[x + i][y + j] != arr[x][y]) {
					check++;
					break;
				}
			}
			if (check == 1) {
				break;
			}
		}
	}
	if (check != 1) {
		if (arr[x][y] == 0) {
			white++;
		}
		else {
			blue++;
		}
	}
	else {	// check == 1
		cut(x, y, n / 2);
		cut(x + n / 2, y, n / 2);
		cut(x, y + n / 2, n / 2);
		cut(x + n / 2, y + n / 2, n / 2);
	}
	return;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);	// blue: 1, white: 0
		}
	}
	cut(0, 0, n);
	printf("%d\n%d", white, blue);
	return 0;
}
