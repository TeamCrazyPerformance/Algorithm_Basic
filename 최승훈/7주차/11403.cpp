#include<iostream>
#include<vector>

using namespace std;
void DFS(vector<vector<int>>& line, vector<int>& answer, int x)
{
	for (int i = 0; i < line[x].size(); i++)
	{
		if (!answer[line[x][i]])
		{
			answer[line[x][i]] = 1;
			DFS(line, answer, line[x][i]);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, num;
	cin >> N;
	vector<vector<int>> line(N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> num;
			if (num)
				line[i].push_back(j);
		}
	for (int i = 0; i < N; i++)
	{
		vector<int> answer(N);
		DFS(line, answer, i);
		for (int j = 0; j < N; j++)
			cout << answer[j] << " ";
		cout << "\n";
	}
	return 0;
}
