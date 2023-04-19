#include<iostream>
#include<cmath>
using namespace std;

int z(int n, int r, int c) {
	int ans = 0;
	if (n == 1) {
		if (r == 1) {
			ans += 2;
		}
		if (c == 1) {
			ans += 1;
		}
		return ans;
	}
	int a = pow(2, n);
	int half = a / 2;
	if (r < half) {
		if (c < half) {
			return z(n - 1, r, c);
		}
		else if (c < a) {
			return half * half + z(n - 1, r, c - half);
		}
	}
	else if (r < a) {
		if (c < half) {
			return 2 * half * half + z(n - 1, r - half, c);
		}
		else if (c < a) {
			return 3 * half * half + z(n - 1, r - half, c - half);
		}
	}
}

int main() {
	int n, r, c;
	cin >> n >> r >> c;
	cout << z(n, r, c) << endl;
	return 0;
}
