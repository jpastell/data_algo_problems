#include <algorithm>
#include <iostream>
#include <array>

using namespace std;

//base^n
int power(int base, unsigned int n)
{
	if(n == 0 ) return 1;
	int x = power(base,n/2);
	if(n & 1){
		//odd
		return x*x*base;
	}
	else{
		//even
		return x*x;
	}
}


int main ()
{
	cout << power(2,9) << endl;

	return 0;
}