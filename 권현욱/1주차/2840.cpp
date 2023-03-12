#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<char> v(N);
    fill(v.begin(), v.end(), '?');

    int idx = 0;
    for (int i = 0; i < K; i++)
    {
        int S;
        char c;
        cin >> S >> c;

        S %= N;

        if (idx + S >= N)
            idx = (idx + S) % N;
        else
            idx += S;
        
        if (v[idx] != '?' && v[idx] != c)
        {
            cout << "!\n";
            return 0;
        }
        else    
            v[idx] = c;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (v[i] != '?' && v[i] == v[j])
            {
                cout << "!\n";
                return 0;
            }
        }
    }
    
    for (int i = N; i > 0; i--) // 반시계 방향으로 출력.
        cout << v[(i + idx) % N];

    return 0;
}
