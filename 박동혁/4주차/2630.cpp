#include <iostream>

using namespace std;

int paper[130][130];
int white, blue;
void divide(int row, int column, int size)
{
    int criterion = paper[row][column];
    for (int i = row; i < row + size; i++)
    {
        for (int j = column; j < column + size; j++)
        {
            if (paper[i][j] != criterion)
            {
                divide(row, column, size / 2);
                divide(row + size / 2, column, size / 2);
                divide(row, column + size / 2, size / 2);
                divide(row + size / 2, column + size / 2, size / 2);
                return;
            }
        }
    }
    if (criterion == 0)
    {
        white++;
    }
    else
        blue++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> paper[i][j];
        }
    }
    divide(1, 1, n);
    cout << white << '\n'
         << blue;
}
