#include<iostream>
using namespace std;

unsigned long long city_distance[99999];
unsigned long long cost[100000];

int main() {
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> city_distance[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	unsigned long long ans = 0, sum_distance = 0, low_cost_city = 0;
	for (int i = 0; i < n - 1; i++) {
		if (cost[i - low_cost_city] <= cost[i + 1]) {
			sum_distance += city_distance[i];
			low_cost_city++;
		}
		else {
			ans += cost[i - low_cost_city] * (sum_distance+city_distance[i]);
			low_cost_city = 0;
			sum_distance = 0;
		}
	}
	if (sum_distance) {
		ans += cost[n - 1 - low_cost_city] * sum_distance;
	}
	cout << ans;
	return 0;
}
