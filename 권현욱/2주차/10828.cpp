#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    stack<int> s;
    string str;

    for (int i = 0; i < N; i++)
    {
        cin >> str;

        if (str == "push")
        {
            int num;
            cin >> num;
            s.push(num);
        }
        else if (str == "pop")
        {
            if (s.empty())
                cout << "-1" << "\n";
            else 
            {
                cout << s.top() << "\n";
                s.pop();
            }
        }
        else if (str == "size")
            cout << s.size() << "\n";
        else if (str == "empty")
        {
            if (s.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (str == "top")
        {
            if (s.empty())
                cout << -1 << "\n";
            else
                cout << s.top() << "\n";
        }
    }

    return 0;
}
