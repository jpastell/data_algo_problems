#include <iostream>
#include <array>

using std::cout;
using std::endl;

int comp_function(void const *a, void const*b)
{
	int const* int_a = static_cast<int const*>(a);
	int const* int_b = static_cast<int const*>(b);
	return int_a - int_b;
}

void swap(int &a_ptr, int &b_ptr)
{
	int temp = b_ptr;
	b_ptr = a_ptr;
	a_ptr = temp;
}

void print( int array[], size_t size)
{
	for(size_t i =0; i <= size-1 ; i ++)
	{
		cout<< array[i] << endl;
	}

	cout  << "--------------------------" << endl;
}

void qsort(int array[], size_t array_size)
{

	if(array_size >= 2)
	{
		for(size_t i = 1; i <= array_size-1; i++)
		{
			if(array[i-1] > array[i])
			{
				swap(array[i],array[i-1]);
				for(size_t j = i-1 ; j >= 1 ; j--)
				{
					if(array[j-1] > array[j])
					{
						swap(array[j],array[j-1]);
					} else {
						break;
					}
				}
			}
		}

		
	}
}



int main (int arc, char* argv[])
{
	int test_array[] = {5,6,3,5,7,4,2,1,2};
	print(test_array, sizeof(test_array)/sizeof(int));

	cout << "++++++++++++++++++++" << endl;
	qsort(test_array, sizeof(test_array)/sizeof(int));
	
	cout << "++++++++++++++++++++" << endl;
	print(test_array, sizeof(test_array)/sizeof(int));
	// 
	// int a = 3;
	// int b = 2;
	// swap(a,b);
	// cout << a << endl;
	// cout << b << endl;

	return 0;
}