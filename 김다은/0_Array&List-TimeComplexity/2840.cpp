#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;
	int spin;
	cin >> spin;

	char* circle = new char[num];
	for (int i = 0; i < num; i++) { circle[i] = '?'; }

	int curSpin;
	char curChar;

	int pntNum = 0;

	int flag = 0;

	for (int i = 0; i < spin; i++) {
		cin >> curSpin;
		cin >> curChar;

		pntNum += curSpin;

		int wher = pntNum % num;

		if (circle[wher] != '?' && circle[wher] != curChar) { flag = 1; break; }
		circle[wher] = curChar;
	}

	if (flag != 0) { cout << '!';}
	else {
		for (int i = 0; i < num; i++) {
			cout << circle[num - i - 1];
//			int k = (i + spin) % num;
//			cout << circle[num-k-1]; 
		}
	}

	return 0;
}