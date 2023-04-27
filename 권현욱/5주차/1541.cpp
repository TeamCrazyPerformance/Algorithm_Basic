#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;

    bool PlusMinus = false; // false : Plus
    string num;

    int result = 0;
    for (int i = 0; i <= str.size(); i++)
    {
        // 연산자 혹은 마지막 자리이면 계산 진행.
        if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
        {
            if (PlusMinus)
            {
                result -= stoi(num);
                num = "";
            }
            else
            {
                result += stoi(num);
                num = "";
            }
        }
        else
        {
            // 피연산자의 경우 연산자를 만나기 전까지 숫자로 취급해서 문자열에 넣기.
            num += str[i];
        }

        // '-'부호가 나온 순간부터는 다 뺴주면 최솟값이 나옴.
        if (str[i] == '-')
            PlusMinus = true;
    }

    cout << result << "\n";
}
