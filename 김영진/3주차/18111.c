#include<stdio.h>

int main() {
	int n, m, b;
	scanf("%d %d %d", &n, &m, &b);
	int max_h = 0, min_time = 0, result_h;
	int ground[500][500];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &ground[i][j]);
			if (ground[i][j] > max_h) {
				max_h = ground[i][j];
			}
		}
	}
	for (int h = max_h; h >= 0; h--) {
		int time = 0;
		int dirt = b;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (ground[i][j] == h) {

				}
				else if (ground[i][j] < h) {
					time += h - ground[i][j];
					dirt -= h - ground[i][j];
				}
				else if (ground[i][j] > h) {
					time += 2 * (ground[i][j] - h);
					dirt += ground[i][j] - h;
				}
			}
		}
		if (dirt < 0) {
			continue;
		}
		if (time < min_time || min_time == 0) {
			min_time = time;
			result_h = h;
			if (min_time == 0) {
				break;
			}
		}
	}
	printf("%d %d", min_time, result_h);
	return 0;
}
