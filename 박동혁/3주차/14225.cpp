#include<iostream>
#define max 2000001

using namespace std;

int n, sum;
int arr[21];
bool check[max];
void recur(int cnt) 
{
    if(cnt==n) 
        return;
    for( ; cnt<n; cnt++) {
        sum += arr[cnt];
        check[sum] = true;
        recur(cnt+1);
        sum -= arr[cnt];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int cnt=0;
    recur(cnt);

    for(int i=1; i<max; i++) {
        if(!check[i]) {
            cout << i;
            return 0;
        }
    }
}