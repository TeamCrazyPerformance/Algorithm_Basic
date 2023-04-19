#include <iostream>

using namespace std;

long long cal(long long a, long long b, long long c)
{
    if(b==1) return a % c;
    long long ans = cal(a, b/2, c);

    ans = ans * ans % c; // x^(2n) = x^n * x^n
    if(b%2==0) return ans;
    else return ans * a % c; // ans = x^(2n)이므로 x^(2n+1) = x^2n * x
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long a, b, c, ans;
    cin >> a >> b >> c;

    cout << cal(a, b, c);
}
