#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n; 
    cin >> n;
    n = n*(n-1)*(n-2)/6; // nC3
    cout << n << '\n' << 3;
}