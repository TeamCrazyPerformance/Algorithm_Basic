#include <iostream>

using namespace std;

int main() {
	int aF;
	int bF;
	cin >> aF;
	cin >> bF;

	int aG;
	cin >> aG;
	int x;
	cin >> x;

	if (aF * x + bF > aG * x) cout << 0;
	else if (aF > aG) cout << 0;
	else cout << 1;

	return 0;
}