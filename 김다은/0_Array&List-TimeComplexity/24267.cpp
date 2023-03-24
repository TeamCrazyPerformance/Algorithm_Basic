#include <iostream>

using namespace std;


int main()
{
	long long num;
	cin >> num;
	
	long long many = 0;
	int power=3;
	
	/*
	if (num <= 2) { many = 0; power = 0; }
	else many = (num - 2) * (num - 1) * num / 6; 	
	*/

	many = (num - 2) * (num - 1) * num / 6;

	cout << many << endl;
	cout << power;
	
	return 0;
}
