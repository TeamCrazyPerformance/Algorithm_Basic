#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<pair<int, int>> edge;
int cnt = 1;
int visited[100001] = { 0 };
int location[100001] = { 0 };
int start;

bool compare(pair<int, int> x1, pair<int, int>x2) {
	if (x1.first == x2.first) return x1.second > x2.second;
	else return x1.first < x2.first;
}

void DFS(int v) {
	if (visited[v]) return;
	else {
		visited[v] = cnt++;
		for (int i = location[v]; i < edge.size() && edge[i].first == v; i++) DFS(edge[i].second);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, r;
	cin >> n >> m >> r;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		edge.push_back(make_pair(a, b));
		edge.push_back(make_pair(b, a));
	}
	sort(edge.begin(), edge.end(), compare);
	start = edge[0].first;
	for (int i = 1; i < edge.size(); i++) {
		if (edge[i].first != edge[i - 1].first) location[edge[i].first] = i;
	}
	DFS(r);
	for (int i = 1; i <= n; i++) cout << visited[i] << "\n";
	return 0;
}
