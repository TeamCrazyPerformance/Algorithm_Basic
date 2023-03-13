#include<iostream>
#include<list>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    list<int> li;
    for(int i=1; i<=n; i++) {
        li.push_back(i);
    }
    
    list<int>::iterator it = --li.end();
    cout << '<';
    while(n--) {
        int tmp = k;
        while(tmp--) {
            ++it;
            it = (it == li.end()) ? li.begin() : it;
        }
        cout << *it;
        li.erase(it);
        if(it!=li.begin()) --it;
        if(li.empty()) {
            cout << '>';
            return 0;
        }
        cout << ", ";
    }
}