#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int A, B;
	cin >> A >> B;
	int ans = 1;
	while (A < B) {
		ans++;
		if (B % 10 == 1) {
			B /= 10;
		}
		else if (!(B & 1)) {
			B >>= 1;
		}
		else {
			break;
		}
	}
	if (A == B) {
		cout << ans;
	}
	else {
		cout << "-1";
	}
	return 0;
}
