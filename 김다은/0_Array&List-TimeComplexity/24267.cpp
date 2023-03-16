#include <iostream>

using namespace std;


int main()
{
	int num;
	cin >> num;
	
	int many=0;
	int power=3;
	
	//(N-2 - i)(N-1-i)/2 ( i )
	
	for (int i = 1; i <=num-3; i++ ){
	    many += i *(num - 2 - i)*(num - 1 - i)/2;
	}
	
	cout << many << endl;
	cout << power;
	
}
