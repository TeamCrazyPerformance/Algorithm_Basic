#include<iostream>
#include <cmath>
#include <string>

using namespace std;

void HanoiTower(int num, int from, int by, int to)
{
	if (num == 1) 
		printf("%d %d\n", from, to);
	else
	{
		// from -> by -> to
		// num -1 만큼 by로 옮김 -> 1개 to로 옮김 -> by to로 옮김  
		HanoiTower(num - 1, from, to, by); 
		printf("%d %d\n", from, to);
		HanoiTower(num - 1, by, from, to);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;

	string ans = to_string(pow(2, N));

	int x = ans.find('.');				//pow 함수 결과가 실수형이기에 소수점 찾기
	ans = ans.substr(0, x);				//소수점 앞자리만 나오게하기
	ans[ans.length() - 1] -= 1;			//string a에 대한 마지막 위치의 인덱스 값에 -1

	cout << ans << endl;

	if (N <= 20)
		HanoiTower(N, 1, 2, 3);

	return 0;
}
