#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
	vector<int> a(3);
	int c, n0;
	for (int i = a.size() - 1; i >= 0; i--)
		cin >> a[i];
	cin >> c >> n0;
	if (a[2] > c)
		cout << 0;
	else if (a[2] == c)
	{
		if (a[1] > 0)
			cout << 0;
		else {
			double x = (double)a[0] / (-a[1]);
			if ((double)n0 < x)
				cout << 0;
			else
				cout << 1;
		}
	}
	else
	{
		a[2] = c - a[2];
		a[1] = -a[1];
		a[0] = -a[0];
		int D = a[1] * a[1] - 4 * a[2] * a[0];
		if (D <= 0)
			cout << 1;
		else
		{
			double x = (-a[1] + sqrt(D)) / (2.0 * a[2]);
			if ((double)n0 < x)
				cout << 0;
			else
				cout << 1;
		}
	}
	return 0;
}
