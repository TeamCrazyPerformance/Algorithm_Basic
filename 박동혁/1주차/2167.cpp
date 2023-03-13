#include<iostream>

using namespace std;

int arr[302][302];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k, i, j, x, y;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> k;
    while(k--) {
        int sum=0;
        cin >> i >> j >> x >> y;
        for(int x1=i; x1<=x; x1++) {
            for(int y1=j; y1<=y; y1++) {
                sum += arr[x1][y1];
            }
        }
        cout << sum << '\n';
    }
}