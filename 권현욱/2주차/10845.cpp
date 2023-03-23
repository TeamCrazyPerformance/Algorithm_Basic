#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    queue<int> q;
    string str;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> str;

        if (str == "push")
        {
            int X;
            cin >> X;
            q.push(X);
        }
        else if (str == "pop")
        {
            if (q.empty())
                cout << "-1" << "\n";
            else
            {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if (str == "size")
        {
            cout << q.size() << "\n";
        }
        else if (str == "empty")
        {
            if (q.empty())
                cout << "1" << "\n";
            else
                cout << "0" << "\n";
        }
        else if (str == "front")
        {
            if (q.empty())
                cout << "-1" << "\n";
            else    
                cout << q.front() << "\n";
        }
        else if (str == "back")
        {
            if (q.empty())
                cout << "-1" << "\n";
            else
                cout << q.back() << "\n";
        }
    }

    return 0;
}
