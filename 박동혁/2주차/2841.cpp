#include<iostream>
#include<stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, p, line, fret, cnt=0;
    stack<int> stk[7];
    cin >> n >> p;
    while(n--) {
        cin >> line >> fret;
        if(stk[line].empty()) {
            stk[line].push(fret);
            cnt++;
            continue;
        }
        while(stk[line].top() != fret) {
            if(stk[line].top() > fret) {
                stk[line].pop();
                if(stk[line].empty()) {
                    stk[line].push(fret);
                    cnt++;
                }
            } else if(stk[line].top() < fret) {
                stk[line].push(fret);
            }
            cnt++;
        }
    }
    cout << cnt;
}