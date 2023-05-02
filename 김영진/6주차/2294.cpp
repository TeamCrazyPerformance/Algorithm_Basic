#include<iostream>
#include<algorithm>
#define MAX 10001
using namespace std;

int value[100] = { 0 };
int dp[10001] = { 0 };

int count_coin(int n, int k) {
	if(dp[k] == MAX){
		for (int i = 99; i > 99 - n; i--) {
			if (value[i] && value[i] <= k) {
				if (dp[k - value[i]] > MAX) {
					continue;
				}
				dp[k] = min(dp[k], 1 + count_coin(n, k - value[i]));
			}
		}
	}
	if (dp[k] == MAX) {
		dp[k] = MAX + 1;
	}
	return dp[k];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> value[i];
	}
	sort(value, value + 100);
	for (int i = 0; i < 10001; i++) dp[i] = MAX;
	for (int i = 0; i < 100; i++) {
		if (value[i] < 10001) {
			dp[value[i]] = 1;
		}
	}
	int ans = count_coin(n, k);
	if (ans < MAX) {
		cout << ans;
	}
	else {
		cout << "-1";
	}
	return 0;
}
