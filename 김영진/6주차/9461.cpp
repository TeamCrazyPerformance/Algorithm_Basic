#include<iostream>
using namespace std;

long long dp[101] = { 0,1,1,1,2,2 };

long long padoban(int n) {
	if (n <= 3) {
		return 1;
	}
	else if (n <= 5) {
		return 2;
	}
	if (dp[n]) {
		return dp[n];
	}
	return dp[n] = padoban(n - 1) + padoban(n - 5);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	int n;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << padoban(n) << "\n";
	}
	return 0;
}
