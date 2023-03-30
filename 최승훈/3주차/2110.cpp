#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int N, C;
	cin >> N >> C;

	vector<int> coo(N);
	for (int i = 0; i < N; i++)
		cin >> coo[i];
	sort(coo.begin(), coo.end());
	
	int start = 0, end = coo[N - 1] - coo[0];
	int result = 0;
	while (start <= end)
	{
		int router = 1;
		int mid = (start + end) / 2;
		int loc = coo[0];
		for (int i = 1; i < N; i++)
		{
			int interval = coo[i] - loc;
			if (interval > mid)
			{
				loc = coo[i];
				router++;
			}
		}
		if (C <= router)
		{
			result = max(result, mid);
			start = mid + 1;
		}
		else
			end = mid - 1;
	}

	cout << start;
	return 0;
}
