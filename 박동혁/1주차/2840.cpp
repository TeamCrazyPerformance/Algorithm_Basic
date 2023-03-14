#include<iostream>

using namespace std;

bool check[27];
char arr[27];
int main()
{
    int n, k, s;
    char c;
    cin >> n >> k;
    int flag = 1;
    while(k--) {
        cin >> s >> c;
        while(s--) {
            flag++;
            flag = (flag > n) ? 1 : flag;
        }
        if((arr[flag]!='\0' && arr[flag]!=c) || (check[c-'A'] && arr[flag]=='\0')) {
            cout << '!';
            return 0;
        }
        check[c-'A']=true;
        arr[flag]=c;
    }
    for(int i=0; i<n; i++) {
        if(arr[flag]=='\0') cout << '?';
        else cout << arr[flag];
        flag--;
        flag = (flag < 1) ? n : flag;
    }
}