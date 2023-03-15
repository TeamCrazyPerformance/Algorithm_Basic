#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a1, a0, c, n0;
    cin >> a1 >> a0 >> c >> n0;
    if((a1 * n0 + a0 <= c * n0) && c>=a1)
        cout << 1;
    else cout << 0;
}