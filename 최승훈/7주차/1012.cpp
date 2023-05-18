#include<iostream>
#include<vector>
using namespace std;

int dy[] = { 0, 0, -1, 1 };
int dx[] = { -1, 1, 0 ,0 };

void DFS(vector<vector<int>>& map, vector<vector<int>>& visited, int k, int w)
{
	visited[k][w] = 1;
	int M = map[0].size();
	int N = map.size();
	for (int i = 0; i < 4; i++)
	{
		int nx = w + dx[i];
		int ny = k + dy[i];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N)
			continue;
		if (map[ny][nx] == 1 && visited[ny][nx] == 0)
			DFS(map, visited, ny, nx);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int T, M, N, K;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> K;
		vector<vector<int>> map(N, vector<int>(M, 0));
		vector<vector<int>> visited(N, vector<int>(M, 0));
		for (int j = 0; j < K; j++)
		{
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}
		int cnt = 0;
		for (int k = 0; k < N; k++)
		{
			for (int w = 0; w < M; w++)
			{
				if (map[k][w] == 1 && visited[k][w] == 0) {
					DFS(map, visited, k, w);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
