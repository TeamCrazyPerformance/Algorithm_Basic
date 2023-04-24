#include<iostream>
using namespace std;

int main() {
	cin.tie(0), cout.tie(0);
	int n, k, ans = 0;
	cin >> n >> k;
	int coin[10];
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		while (k >= coin[i]) {
			ans++;
			k -= coin[i];
		}
	}
	cout << ans;
	return 0;
}
