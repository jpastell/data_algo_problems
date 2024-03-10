#include <iostream>
#include <cstdint>

using std::cout;
using std::cin;
using std::endl;

void half_square_tringle()
{
	for(uint32_t i = 5 ; i >=1; i-- )
	{
		for(uint32_t j = 1; j<=i ; j++)
		{
			cout << "#";
		}
		cout << endl;
	}
}

void half_square_tringle_up()
{
	for(uint32_t i = 1 ; i <=4; i++ )
	{
		for(uint32_t j = 1; j<=i ; j++)
		{
			cout << "#";
		}
		cout << endl;
	}
}





int main(int argc , char* argv [])
{
	half_square_tringle_up();
	half_square_tringle(); 
	return 0;
}