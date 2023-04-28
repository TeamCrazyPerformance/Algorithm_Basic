#include<iostream>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string str;
	cin >> str;
	int minus[51] = { -1 }, plus = 0;
	int num[51] = { 0 };
	int i;
	for (i = 1; str.find('-', minus[i - 1] + 1) != -1; i++) {
		minus[i] = str.find('-', minus[i - 1] + 1);
		string tmp = str.substr(minus[i - 1] + 1, minus[i] - minus[i - 1]);
		num[i] += stoi(tmp);
		for (int j = 1; tmp.find('+') != -1; j++) {
			plus = tmp.find('+');
			tmp = tmp.substr(plus + 1);
			num[i] += stoi(tmp);
		}
	}
	string tmp;
	if (minus[1]) {
		tmp = str.substr(minus[i - 1] + 1, minus[i] - minus[i - 1]);
	}
	else {
		tmp = str;
	}
	num[i] += stoi(tmp);
	for (int j = 1; tmp.find('+') != -1; j++) {
		plus = tmp.find('+');
		tmp = tmp.substr(plus + 1);
		num[i] += stoi(tmp);
	}
	int ans = num[1];
	for (int x = 2; x < 51; x++) {
		ans -= num[x];
	}
	cout << ans;
	return 0;
}
