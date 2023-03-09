#include <iostream>

using namespace std;

int main() {
	int row;
	int col;

	cin >> row;
	cin >> col;

	int** arrai = new int*[row];

	for (int i = 0; i < row; i++) arrai[i] = new int[col];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> arrai[i][j];
		}
	}

	int sNum;
	cin >> sNum;

	int iRow, iCol;
	int lRow, lCol;

	int sum;

	for (int i = 0; i < sNum; i++) {
		sum = 0;

		cin >> iRow >> iCol;
		cin >> lRow >> lCol;

		for (int j = iRow - 1; j < lRow; j++) {
			for (int k = iCol - 1; k < lCol; k++) { sum += arrai[j][k]; }
		}

		cout << sum << endl;
	}
}