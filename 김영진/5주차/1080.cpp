#include<iostream>
#include<string>
using namespace std;

int A[50][50];
int B[50][50];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	string tmp[50];
	for (int i = 0; i < n; i++) {
		cin >> tmp[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			A[i][j] = (int)tmp[i][j] - 48;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> tmp[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			B[i][j] = (int)tmp[i][j] - 48;
		}
	}
	int ans = 0;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			if (A[i - 1][j - 1] != B[i - 1][j - 1]) {
				ans++;
				for (int x = i - 1; x <= i + 1; x++) {
					for (int y = j - 1; y <= j + 1; y++) {
						if (A[x][y]) {
							A[x][y]--;
						}
						else {
							A[x][y]++;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] != B[i][j]) {
				cout << "-1";
				return 0;
			}
		}
	}
	cout << ans;
	return 0;
}
