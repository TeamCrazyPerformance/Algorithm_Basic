#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int beauty[101] = { 0 };
	for (int i = 1; i < 101; i++)
		beauty[i] = -1;
	
	int tmp;
	cin >> tmp;
	beauty[tmp] = 0;

	for (int i = 1; i < N; i++)
	{
		int val; 
		cin >> val;

		for (int j = 1; j < 101; j++)
		{
			if (beauty[j] > -1)
				beauty[val] = max(beauty[val], beauty[j] + (val - j) * (val - j));
		}
	}
	int answer = 0;
	for (int i = 1; i < 101; i++)
		answer = max(answer, beauty[i]);

	cout << answer;

	return 0;
}
