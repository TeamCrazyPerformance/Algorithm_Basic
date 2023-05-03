#include<iostream>
#define mod 1000000000

using namespace std;

int dp[101][10];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for(int i=1; i<=9; i++)
		dp[1][i]=1;
	for(int i=2; i<=n; i++) {
		for(int j=0; j<=9; j++) {
			if(j==0)
				dp[i][j]=dp[i-1][1]%mod;
			else if(j==9)
				dp[i][j]=dp[i-1][8]%mod;
			else
				dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%mod;
		}
	}
	long long result=0;
	for(int i=0; i<=9; i++)
		result += dp[n][i];
	cout << result%mod;
	
	return 0;
}
