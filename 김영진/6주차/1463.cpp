#include<iostream>
using namespace std;

int dp[1000001] = { 0,0,1,1 };

int tabulation(int n) {
	if (n == 1) {
		return 0;
	}
	if (dp[n]) {
		return dp[n];
	}
	if (n % 3 == 0) {
		if (!(n & 1)) {
			if (dp[n / 2] < dp[n / 3]) {
				return dp[n] = dp[n / 2] + 1;
			}
		}
		if (dp[n - 1] < dp[n / 3]) {
			return dp[n] = dp[n - 1] + 1;
		}
		return dp[n] = dp[n / 3] + 1;
	}
	else if (!(n & 1)) {
		if (dp[n - 1] < dp[n / 2]) {
			return dp[n] = dp[n - 1] + 1;
		}
		return dp[n] = dp[n / 2] + 1;
	}
	return dp[n] = dp[n - 1] + 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = tabulation(i);
	}
	cout << dp[n];
	return 0;
}
