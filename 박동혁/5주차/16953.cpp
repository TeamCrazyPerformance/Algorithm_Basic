#include<iostream>
#include<string>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, ans=1;
    cin >> a >> b;
    while(b>a) {
        if(b%2==0) // 2로 나눠떨어지면 2로 나눠줌
            b/=2;
        else { // 홀수일때
            string tmp=to_string(b); // b를 문자열로 변환
            if(tmp[tmp.length()-1] == '1') { // 마지막 문자가 1이면 끝자리 수를 없앰
                b/=10;
            } else break; // 1을 제외한 홀수이면 아무 연산이 불가하므로 종료
        }
        ans++;
    }
    if(b==a)
        cout << ans;
    else cout << -1;
}