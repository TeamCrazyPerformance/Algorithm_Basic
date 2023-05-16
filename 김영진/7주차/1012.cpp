#include<iostream>
#include<string.h>
using namespace std;

int ground[50][50];
int visited[50][50];

int m, n, k;
int ans;

void DFS(int x, int y) {
	if (x < 0 || m <= x || y < 0 || n <= y) return;
	if (!ground[y][x]) return;
	if (visited[y][x]) return;
	visited[y][x]++;
	DFS(x - 1, y);
	DFS(x, y - 1);
	DFS(x + 1, y);
	DFS(x, y + 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		ans = 0;
		memset(ground, 0, sizeof(ground));
		memset(visited, 0, sizeof(visited));
		cin >> m >> n >> k;
		int x, y;
		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			ground[y][x]++;
		}
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < m; b++) {
				if (visited[a][b]) continue;
				if (!ground[a][b]) continue;
				else {
					ans++;
					DFS(b, a);
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
