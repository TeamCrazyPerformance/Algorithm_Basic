#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long N, temp;
    cin >> N;
    long long K = N - 1;
    long long len = 0;

    vector<long long> Len;
    vector<long long> Cost;

    for (int i = 0; i < K; i++)
    {
        cin >> temp;
        Len.push_back(temp);
        len += temp;
    }

    for (int i = 0; i < K; i++)
    {
        cin >> temp;
        Cost.push_back(temp);
    }

    long long result = 0;
    long long minCost = Cost[0];
    for (int i = 0; i < N; i++)
    {
        result += minCost * Len[i];

        if (minCost > Cost[i + 1])
            minCost = Cost[i + 1];
    }

    cout << result << "\n";
}
