#include<iostream>
using namespace std;

int n, cnt = 0;
int queen_y[14];

bool check(int x) {
	for (int i = 0; i < x; i++) {
		if (queen_y[i] == queen_y[x]) return false;
		if (x - i == abs(queen_y[x] - queen_y[i])) return false;
	}
	return true;
}

void DFS(int x) {
	if (x == n) {
		cnt++;
		return;
	}
	else if (!x && !(n & 1)) {
		for (int i = 0; i < n/2; i++) {
			queen_y[x] = i;
			if (check(x)) DFS(x + 1);
		}
		cnt <<= 1;
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			queen_y[x] = i;
			if (check(x)) DFS(x + 1);
		}
		return;
	}
}

int main() {
	cin >> n;
	DFS(0);
	cout << cnt;
	return 0;
}
