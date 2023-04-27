#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long N;
    cin >> N;

    vector<pair<int, int>> timeTable;
    int start, end;

    for (int i = 0; i < N; i++)
    {
        cin >> start >> end;
        // 회의 종료 시점을 기준으로 함.
        timeTable.push_back(make_pair(end, start));
    }
    sort(timeTable.begin(), timeTable.end());

    int time = timeTable[0].first;
    int count = 1;

    for (int i = 1; i < N; i++)
    {
        if (time <= timeTable[i].second)
        {
            count++;
            time = timeTable[i].first;
        }
    }
    cout << count << "\n";
}
