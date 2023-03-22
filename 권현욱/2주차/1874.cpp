#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    stack<int> s;
    vector<char> answer;
    int Max = 0; // stack에 들어갔었던 최댓값.


    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        while (Max < num)
        {
            ++Max;
            s.push(Max);
            answer.push_back('+');
        }

        if (s.top() == num)
        {
            s.pop();
            answer.push_back('-');
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << "\n";

    return 0;
}
