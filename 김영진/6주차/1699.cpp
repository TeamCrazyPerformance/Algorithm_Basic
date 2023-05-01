#include<iostream>
using namespace std;

int dp[100001] = { 0, 1 };

int tabulation(int n) {
	if (n == 1) {
		return 1;
	}
	if (dp[n] == 0) {
		int max = 100000;
		for (int i = 1; i * i < n; i++) {
			int tmp = tabulation(n - i * i);
			if (tmp < max) {
				max = tmp;
			}
		}
		dp[n] = max + 1;
	}
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i < 317; i++) {
		dp[i * i] = 1;
	}
	cout << tabulation(n);
	return 0;
}
