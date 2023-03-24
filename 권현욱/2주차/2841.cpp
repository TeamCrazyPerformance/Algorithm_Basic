#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, P;
    cin >> N >> P;

    int cnt = 0;

    stack<int> line[7];

    for (int i = 0; i < N; i++)
    {
        int l, p;
        cin >> l >> p;

        // 1. 현재 프렛의 높이를 계산해 높다면 손가락 먼저 제거하기.
        // ex) 3번 줄 5번,7번 프렛 누른 상태에서 3번 줄 2번 프렛 연주하기.
        while (!line[l].empty() && line[l].top() > p)
        {
            line[l].pop();
            cnt++;
        }
        
        // 2. 줄이 아예 비어있거나 손가락을 하나 추가해 프렛의 음을 높이기.
        if (line[l].empty() || line[l].top() < p)
        {
            line[l].push(p);
            cnt++;
        }
    }

    cout << cnt << "\n";
}
