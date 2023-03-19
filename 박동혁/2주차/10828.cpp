#include<iostream>
#include<stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n, num;
	cin >> n;
	string s;
	stack<int> stk;
	while(n--) {
		cin >> s;
		if(s=="push") {
			cin >> num;
			stk.push(num);
		}
		else if(s=="pop") {
			if(stk.empty())
				cout << -1 << '\n';
			else {
				cout << stk.top() << '\n';
				stk.pop();
			}
		}
		else if(s=="size") 
			cout << stk.size() << '\n';
		else if(s=="empty") {
			if(stk.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if(s=="top") {
			if(stk.empty())
				cout << -1 << '\n';
			else
				cout << stk.top() << '\n';
		}
	}
}