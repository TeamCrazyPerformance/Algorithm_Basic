#include<iostream>
#include<algorithm>

using namespace std;

int a[100001];

int search(int n, int num)
{
    int st = 0, end = n-1, ans=0;
    while(st<=end) {
        int mid = (st+end)/2;
        if(num < a[mid]) end = mid-1;
        else if(num > a[mid]) st = mid+1;
        else {
            ans = 1;
            break;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    cin >> m;
    while(m--) {
        int num;
        cin >> num;
        cout << search(n, num) << '\n';
    }
    
    return 0;
}
