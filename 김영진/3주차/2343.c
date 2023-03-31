#include<stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int time[100001] = { 0 };
	int max = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &time[i]);
		sum += time[i];
		if (time[i] > max) {
			max = time[i];
		}
	}
	int start = max;
	int end = sum;
	int mid;
	int j, count;
	int min_time = 1000000000;
	int ex = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		j = 0;
		int bd[100000] = { 0 };
		int bd_max = 0;
		count = 0;
		for (int i = 0; i < m; i++) {
			while (bd[i] <= mid) {
				if (time[j] == 0) {
					break;
				}
				bd[i] += time[j];
				j++;
			}
			if (time[j] != 0 || bd[i] > mid) {
				bd[i] -= time[--j];
			}
			if (bd[i] > bd_max) {
				bd_max = bd[i];
			}
			count++;
			if (time[j] == 0) {
				break;
			}
		}
		if (count < m) {
			if (bd_max < min_time) {
				min_time = bd_max;
			}
			end = mid - 1;
		}
		else if (time[j] != 0) {
			start = mid + 1;
		}
		else if (count == m) {
			if (bd_max < min_time) {
				min_time = bd_max;
				ex++;
			}
			if (start == mid) {
				break;
			}
			end = mid - 1;
		}
	}
	printf("%d", min_time);

	return 0;
}
