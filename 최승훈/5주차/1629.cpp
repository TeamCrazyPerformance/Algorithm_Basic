#include<iostream>
// a^b
/*
3^13
모듈러 성질 : (a * b) % c = (a % c * b % c) % c
*/
using namespace std;
unsigned long multi(unsigned long a, unsigned long b, unsigned long c)
{
	if (!b) // 0승은 1
		return 1;
	if (b == 1) // 1이면 한 번 나누어주기
		return a % c;
	if (b & 1)  // b가 홀수이면  b = 5 -> 4 -> 2 -> 1                 
		return multi(a, b - 1, c) * (a % c) % c; // multi(a, b-1,c) * a % c ?
	// b가 짝수이면
	return multi((a %c)* (a % c) % c, b / 2, c) % c; // multi (a * a % c , b/2, c) % c?
}
// a^5 = (a^4 % c) * (a % c) % c
// a^4 = (a^2 % c) * (a^2 % c) % c
// a^2 = a * a % c
// a^1 = a % c
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	unsigned long a, b, c;
	cin >> a >> b >> c;
	unsigned long d = multi(a, b, c);
	cout << d;

}
