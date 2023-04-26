#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int ans=0, tmp=0;
    bool flag = false;
    for(int i=0; i<s.length(); i++) {
        if(s[i]>='0' && s[i]<='9') {
            if(tmp!=0) tmp *= 10;
            tmp += s[i]-'0';
            continue;
        } else if(flag) {
            ans -= tmp;
            tmp = 0;
            continue;
        } else if(s[i] == '-') {
            flag = true;
        }
        ans += tmp;
        tmp = 0;
    }
    ans = (flag) ? ans-tmp : ans+tmp;
    cout << ans;
}