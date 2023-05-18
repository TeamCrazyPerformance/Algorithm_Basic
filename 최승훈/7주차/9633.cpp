#include<iostream>
#include<vector>

using namespace std;

int total = 0;

bool check(vector<int>& row, int column)
{
    for (int i = 0; i < column; i++)
        // 같은 대각선이거나 같은 열
        // column - i(column 차이) versus row[column] - row[i](row 차이)
        if (row[i] == row[column] || abs(row[column] - row[i]) == column - i)
            return false;
    return true;
}

void nqueen(vector<int>& row, int column, int N)
{
    if (column == N)
        total++;
    else
    {
        for (int i = 0; i < N; i++)
        {
            row[column] = i; // 해당 위치에 퀸을 배치
            // 유효하다면 다음행의 퀸 배치, 유효하지 않다면 i++(다른 위치로 변경)
            if (check(row, column)) 
                nqueen(row, column + 1, N);
        }
    }
}
int main()
{	
	int N;
	cin >> N;
	// 같은 행에는 queen이 있을 수 없다 
    // 따라서 queen이 (1, 1)에 있을 시 1번 째 열 1번 째 행에 있으므로 col[1] = 1 저장
	vector<int> chess(N);
    // N x N 체스판, 
    nqueen(chess, 0, N); 

    cout << total;

	return 0;
}
