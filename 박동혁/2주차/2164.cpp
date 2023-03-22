#include<iostream>
#include<queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    if(n==1) {
        cout << 1;
        return 0;
    }
    queue<int> q;
    for(int i=1; i<=n; i++) {
        q.push(i);
    }
    q.pop();
    while(q.size()!=1) {
        int tmp = q.front();
        q.pop();
        q.push(tmp);
        q.pop();
    }
    cout << q.front();
}