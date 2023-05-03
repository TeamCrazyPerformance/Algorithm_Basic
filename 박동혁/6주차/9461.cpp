#include<iostream>

using namespace std;

long long dp[101];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t;
    dp[0]=dp[1]=dp[2]=1;
    dp[3]=dp[4]=2;
    while(t--) {
        cin >> n;
        if(dp[n-1]!=0) {
            cout << dp[n-1] << '\n';
            continue;
        }
        for(int i=5; i<n; i++) {
            dp[i]=dp[i-5]+dp[i-1];
        }
        cout << dp[n-1] << '\n';
    }
}