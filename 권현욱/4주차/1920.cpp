#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, temp, result;
    vector<int> num;
    vector<int> answer;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        num.push_back(temp);
    }
    sort(num.begin(), num.end());

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> temp;
        result = binary_search(num.begin(), num.end(), temp);
        answer.push_back(result);
    }

    for (int i = 0; i < M; i++)
    {
        cout << answer[i] << " ";
    }
}
