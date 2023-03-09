#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[10];
    for (int i = 0; i < 9; i++)
    {
        cin >> arr[i];

        if (arr[i] >= 100)
            return (0);
    }
    
    int max = 0;
    int idx = 0;

    for (int i = 0; i < 9; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            idx = i;
        }
    }

    cout << max << "\n" << idx + 1;

    return 0;
}
