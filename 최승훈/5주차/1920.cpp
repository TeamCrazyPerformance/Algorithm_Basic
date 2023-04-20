#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool find(vector<int>& seq, int length, int data)
{
	int first = 0, end = length - 1; // index 0부터 시작
	while (first <= end) // 이진 탐색
	{
		int mid = (first + end) / 2;
		if (data > seq[mid])
		{
			first = mid + 1;
		}
		else if (data < seq[mid])
			end = mid - 1;
		else // 같으면 1 반환
			return 1;
	}
	return 0; // 같은 것 없으면 0 반환
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int nums;
	cin >> nums;
	vector<int> seq;
	seq.resize(nums);
	for (int i = 0; i < nums; i++)
	{
		int a;
		cin >> a;
		seq[i] = a;
	}
	sort(seq.begin(), seq.end()); // 이진 탐색 위해서 정렬
	int nums2;
	cin >> nums2;
	vector<int> conf;
	conf.resize(nums2);
	for (int i = 0; i < nums2; i++)
	{
		int b;
		cin >> b;
		conf[i] = find(seq, nums, b); // b 찾고 있으면 1 없으면 0 출력
		cout << conf[i] << " ";
	}
	return 0;
}
