#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K, temp;
    int result = 0;
    cin >> N >> K;

    vector<int> coin;

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        coin.push_back(temp);
    }

    int i = N - 1;
    while (K)
    {
        result += K / coin[i];
        K %= coin[i];

        i--;
    }

    cout << result << "\n";
}
