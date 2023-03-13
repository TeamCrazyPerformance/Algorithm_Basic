#include <iostream>

using namespace std;

long long  sum(long long n)
{
    long long sum = 0;

    for (long long k = 1; k <= n; k++)
    {
        sum += (k * (k + 1)) / 2;
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n; // long long?
    cin >> n;

    long long  count = sum(n - 2);

    cout << count << "\n";
    // cout << (n * (n - 1) * (n - 2)) / 6 << "\n";
    cout << 3;

    return 0;
}
