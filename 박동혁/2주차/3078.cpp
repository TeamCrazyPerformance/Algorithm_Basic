#include<iostream>
#include<queue>

using namespace std;

string name[300001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    long long cnt=0;
    cin >> n >> k;
    queue<int> q[21];
    for(int i=0; i<n; i++) {
        cin >> name[i];
    }
    for(int i=0; i<n; i++) {
        int len = name[i].length();
        while(!q[len].empty() && (q[len].front() < i-k)) 
            q[len].pop();
        cnt += q[len].size();
        q[len].push(i);
    }
    cout << cnt;
}