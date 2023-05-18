#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int cnt = 0;
void DFS(vector<int>& V, vector<vector<int>>& E, int R) 
{
	if (V[R] != 0)
		return;
	cnt++;
	V[R] = cnt;
	for (int i = 0; i < E[R].size(); i++) 
		DFS(V, E, E[R][i]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, R;
	cin >> N >> M >> R;
	vector<vector<int>> graph(M + 1);
	for (int i = 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) 
		sort(graph[i].begin(), graph[i].end(), greater<>());
	vector<int> visited(N + 1, 0);
	DFS(visited, graph, R);
	for (int i = 1; i <= N; i++)
	{
		cout << visited[i] << "\n";
	}
	return 0;
}
