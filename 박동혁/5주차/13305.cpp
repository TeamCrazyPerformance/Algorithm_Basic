#include<iostream>
#define MAX 100001

using namespace std;

int dist[MAX], price[MAX];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n-1; i++)
        cin >> dist[i]; // 거리
    for(int i=0; i<n; i++)
        cin >> price[i]; // 리터당 가격
    long long now_price = price[0], ans=(long long)price[0] * dist[0];
    for(int i=1; i<n; i++) {
        if(price[i] < now_price) {
            now_price = price[i];
        }
        ans += now_price * dist[i];
    }
    cout << ans;
}