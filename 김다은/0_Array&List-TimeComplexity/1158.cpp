#include <iostream>

using namespace std;

int main()
{
	int num;
	int which;

	cin >> num;
	cin >> which;

	int* arr = new int[num];

	for (int i = 0; i < num; i++) arr[i] = i + 1;

	int count = 0;
	int pnt = 0;

	cout << "<";

	while (count < num) {

		for (int i = 0; i < num; i++) {
			if (arr[i] == -1) { ; }
			else {
				pnt++;
				if (pnt % which == 0) {
					if (count != 0) cout << ", ";
					cout << arr[i];
					arr[i] = -1;
					count++;
				}
			}
		}
	}

	cout << ">";
}