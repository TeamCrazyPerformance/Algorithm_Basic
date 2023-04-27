#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int A, B;
    cin >> A >> B;

    int sum = 0;
    while (B)
    {
        if (A > B)
        {
            cout << -1 << "\n";
            return 0;
        }
        else if (A == B)
        {
            sum++;
            break;
        }
        
        if (B % 2 == 0)
            B /= 2;
        else if (B % 10 == 1)
        {
            B--;
            B /= 10;
        }
        else
        {
            cout << -1 << "\n";
            return 0;
        }
        sum++;
    }

    cout << sum << "\n";
}
