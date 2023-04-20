#include <iostream>

using namespace std;

int n, r, c;
int answer;

void Z(int y, int x, int size)
{
    if (y == r && x == c)
    {
        cout << answer << '\n';
        return;
    }

    // r,c가 현재 사분면에 존재한다면
    if (r < y + size && r >= y && c < x + size && c >= x)
    {
        // 1 2
        // 3 4
  
        // 1 탐색
        Z(y, x, size / 2);
        // 2 탐색
        Z(y, x + size / 2, size / 2);
        // 3 탐색
        Z(y + size / 2, x, size / 2);
        // 4 탐색
        Z(y + size / 2, x + size / 2, size / 2);
    }
    else
        answer += size * size;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r >> c;
    Z(0, 0, (1 << n)); // 2^N // n = 2 10b(2d) -> 1000b(8d)
    return 0;
}
