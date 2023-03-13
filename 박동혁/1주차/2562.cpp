#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, max=0, max_index;
    for(int i=1; i<=9; i++) {
        cin >> n;
        if(n > max) {
            max = n;
            max_index = i;
        }
    }
    cout << max << '\n' << max_index << '\n';
}