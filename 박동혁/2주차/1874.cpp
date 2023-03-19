#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int arr[100001];
int main()
{
    int n, num, cnt=1;
    cin >> n;
    stack<int> stk;
    vector<char> ans;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<n; i++) {
        int num = arr[i];
        if(num >= cnt) {
            for( ; cnt<=num; cnt++) {
                stk.push(cnt);
                ans.push_back('+');
            }
            stk.pop();
            ans.push_back('-');
        } else if(num == stk.top()) {
            stk.pop();
            ans.push_back('-');
        } else {
            cout << "NO";
            return 0;
        }
    }
    for(vector<char>::iterator it=ans.begin(); it<ans.end(); it++) {
        cout << *it << '\n';
    }
}