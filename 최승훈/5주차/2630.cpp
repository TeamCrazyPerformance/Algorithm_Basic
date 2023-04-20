#include<iostream>
#include<vector>

using namespace std;

int blue = 0, white = 0;

void cut(vector<vector<bool>>& paper, int row, int col, int length)
{
	bool store, cutornot = 0; // 저장된 값이 0인지 1인지 확인 store 
	                          // 모두 같은지 아닌지 확인 cutornot
	store = paper[row][col]; // store에 정사각형 왼쪽 위 값 넣어주기
	if (length == 1) // 더이상 자를 수 없을 때
	{
		if (store == 0)
			blue++;
		else
			white++;
		return;
	}
	for (int i = row; i < row + length; i++) // * row부터 시작 정사각형 값 같은지 다른지 비교하기
	{
		for (int j = col; j < col + length; j++)
		{
			if (paper[i][j] != store)
			{
				cutornot = 1;
				break;
			}
		}
		if (cutornot == 1) // 다른 값이 있으면 더이상 비교할 필요가 없으므로 break;
			break;
	}

	if (cutornot == 0) // 모두 같다면 색깔 확인
	{
		if (store == 0)
			blue++;
		else
			white++;
	}
	else // 다르다면 자르기
	{
		cut(paper, row, col, length / 2);
		cut(paper, row, col + length / 2, length / 2);
		cut(paper, row + length / 2, col, length / 2);
		cut(paper, row + length / 2, col + length / 2, length / 2);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int length;
	cin >> length;
	vector<vector<bool>> pap(length, vector<bool>(length)); // length x length
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			bool bow;
			cin >> bow;
			pap[i][j] = bow; // 0 또는 1 저장
		}
	}
	cut(pap, 0, 0, length); // 벡터, 가로, 세로, 길이
	cout << blue << "\n" << white;
	return 0; 
}
