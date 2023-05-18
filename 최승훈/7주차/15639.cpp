#include<iostream>
#include<vector>

using namespace std;

vector<int> num;
vector<bool> visited;
int N, M;
void re(int depth)
{
	// depth가 M인 경우 출력해주기
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << num[i] << " ";
		}
		cout << "\n";
		return;
	}
	// re(1)을 N번 수행 re(1) -> re(2) -> ... -> re(M) (출력)
	for (int i = 1; i <= N; i++) {
		// 방문한 경우 false 방문하지 않은 경우 if문 수행
		if (!visited[i]) {
			visited[i] = true;
			num[depth] = i;
			re(depth + 1);
			visited[i] = false;
		}
	}
}
int main()
{
	cin >> N >> M; // NPM
	num.resize(M);
	visited.resize(N + 1);
	re(0);
	return 0;
}
