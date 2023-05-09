#include<iostream>
using namespace std;

int n, m;
int arr[9] = { 0 };
bool visited[9] = { 0 };

void DFS(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[cnt] = i;
            DFS(cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	DFS(0);
	return 0;
}
