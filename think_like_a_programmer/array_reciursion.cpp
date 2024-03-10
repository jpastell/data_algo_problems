#include <iostream>

using std::cout;
using std::endl;

int sum_itr(size_t arr_size, int array[])
{
	int sum = 0;
	for(size_t i = 0; i <= arr_size-1; i++)
	{
		sum += array[i];
	}
	return sum;
}

int sum_head(size_t arr_size, int array[])
{
	
	if(arr_size == 0) return 0;
	int last_num = array[arr_size-1];
	int all_but_last = sum_head(arr_size-1,array);
	return last_num + all_but_last;
}

int sum_tail(size_t arr_size, int array[], size_t index=0, int sum=0)
{
	
	if(index == arr_size) return sum;
	int my_sum = sum + array[index];
	return sum_tail(arr_size,array,index+1,my_sum);
}




int main(int argc, char* argv[])
{
	int array_test[] = {0,1,2,3,4,5,6,7,8,9};
	cout << "Iterative adition: " << sum_itr(sizeof(array_test)/sizeof(int),array_test) << endl;
	cout << "sum_head: " << sum_head(sizeof(array_test)/sizeof(int),array_test) << endl;
	cout << "sum_tail: " << sum_tail(sizeof(array_test)/sizeof(int),array_test) << endl;
}