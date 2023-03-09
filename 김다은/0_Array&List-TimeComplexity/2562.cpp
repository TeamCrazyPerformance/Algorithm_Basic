#include<iostream>

using namespace std;

int main() {

	int tmpNum;
	int max;
	int index;

	for (int i = 0; i < 9; i++) {
		cin >> tmpNum;
		if (i == 0) { max = tmpNum; index = i + 1; }

		if (tmpNum > max) { max = tmpNum; index = i + 1; }
	}

	cout << max << endl;
	cout << index;
}