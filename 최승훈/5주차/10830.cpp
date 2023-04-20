#include<iostream>
#include<vector>

using namespace std;
// 행렬 제곱하기
void tothepowerofN(vector<vector<int>>& matrix1, vector<vector<int>>& matrix2)
{
	int len = matrix1.size(); // 정방행렬이므로 벡터의 사이즈 사용
	vector<vector<int>> temp(len, vector<int>(len)); // 벡터 temp len x len
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			for (int k = 0; k < len; k++)
				temp[i][j] += (matrix1[i][k] * matrix2[k][j]); // 00*00+01*10 00*01+01*11
			temp[i][j] %= 1000;                                // 10*00+11*10 10*01+11*11
			//행렬의 각 원소는 1,000보다 작거나 같은 자연수 또는 0이다. 미리 나누어줘도 된다...
			//int이므로 숫자가 커지기 전에 나누어주기
		}
	}
	// 벡터 temp의 값을 matrix1에 복사하기
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
			matrix1[i][j] = temp[i][j];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	unsigned long n, b; // b가 매우 크고 양수이므로 unsigned long으로 선언
	cin >> n >> b;

	vector<vector<int>> matrix1(n, vector<int>(n)); // n x n
	vector<vector<int>> matrix2(n, vector<int>(n)); // n x n

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> matrix1[i][j]; //입력값 matrix1에 저장
		matrix2[i][i] = 1; // 곱해서 A * I = A 단위행렬
	}

	while (b > 0) { // b를 2로 나눈 값이 0보다 클 때까지 반복
		if (b & 1) { // b가 홀수일 때 
			tothepowerofN(matrix2, matrix1); // ret=ret*a matrix2에 곱한 값 저장
		}
		tothepowerofN(matrix1, matrix1); // a*=a matrix1에 곱한 값 저장
		b >>= 1;
		// b = 5 행렬을 a라고 할 때
		// 1. b가 홀수이므로 matrix2 = a matrix1 = a^2
		// 2. b = 2 짝수 matrix2 = a matrix1 = a^4
		// 3. b = 1 홀수 matrix2 * matrix1 = a^5
	}

	for (int i = 0; i < n; i++) //출력
	{
		for (int j = 0; j < n; j++)
			cout << matrix2[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
