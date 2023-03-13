#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a1, a0;
    cin >> a1 >> a0;
    int c, n0;
    cin >> c >> n0;

    if (a1 == c)
    {
        if (a0 <= 0)
            cout << 1;
        else
            cout << 0;
        return 0;
    }
    else if (a1 > c)
    {
        cout << 0;
        return 0;
    }
    else
    {
        if ((c - a1) * n0 >= a0)
            cout << 1;
        else
            cout << 0;

        return 0;
    }

    return 0;
}
