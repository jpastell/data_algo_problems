#include <algorithm>
#include <iostream>
#include <array>

template <typename T, std::size_t S>
void selection_sort(std::array<T,S> &array)
{
	size_t length = array.size();
	for(size_t ord_i = 0 ; ord_i < length-1; ord_i++)
	{
		size_t min_idx = ord_i;
		for(size_t search_i = ord_i+1 ; search_i < length; search_i++)
		{
			if(array[min_idx] > array[search_i])
			{
				min_idx = search_i;
			}
		}
		std::swap(array[ord_i],array[min_idx]);
	}
}

//swap out the grater or smaller number to the end
//or the array. Reuce the array by 1 and do the same until
//the end
template <typename T, std::size_t S>
void buble_sort(std::array<T,S> &array)
{
	size_t size = array.size();
	//we sjut nedd to iterate form 0 to n-1 
	for(size_t step = 0 ; step < (size-1); step++)
	{
		//the end of the array is size - 1, we reduce the step
		//to indicate that we are moving one positin from  the 
		//rigth to the begining
		for(size_t i = 0; i < (size-1)-step; i++)
		{
			 if(array[i] > array[i + 1])
			 {
			 	std::swap(array[i],array[i + 1]);
			 }
		}
	}
}

template <class Iterator>
void selection_sort(Iterator begin, Iterator end)
{
	for(Iterator i = begin; i != end ; i++)
	{
		std::iter_swap(i,std::min_element(i,end));
	}
}

template <class Iterator>
void print_container(Iterator begin, Iterator end)
{
	for(Iterator i = begin; i != end ; i++)
	{
		std::cout << *i << ",";
	}
	std::cout << std::endl;
}

template <class Iterator>
void buble_sort(Iterator begin, Iterator end)
{
	for(Iterator i = begin; i != end ; i++)
	{
		for(Iterator j=i+1; j != end ; j++)
		{
			if(*i > *j) std::iter_swap(i,j);
		}
	}

}

// template <typename T, std::size_t S>
// void insertion_sort(std::array<T,S> &array)
// {
// 	int n = array.size();
// 	for(int i = 1 ; i < n; i++)
// 	{
// 		std::cout << "---i" << i << std::endl;
// 		int j = i;
// 		std::cout << "Outside: array[j]=" << array[j] << " array[j-1]=" << array[j-1] << std::endl;
		
// 		while((j>0) && (array[j] < array[j-1]))
// 		{
// 			std::cout << "array[j]=" << array[j] << " array[j-1]=" << array[j-1] << std::endl;
// 			std::cout << "j" << j << std::endl;
// 			std::swap(array[j],array[j-1]);
// 			j--;
// 		}
// 	}
// }
// 

template <typename T, std::size_t S>
void insertion_sort(std::array<T,S> &array)
{
	size_t n = array.size();
	for(size_t i = 1 ; i < n; i++)
	{
		for(size_t j = i ;  j >= 1 ; j--)
		{

			if(array[j-1] > array[j])
			{
				std::swap(array[j],array[j-1]);
			}
			else 
			{
				break;
			}
		}
	}

}



int main ()
{

	std::array<int,5> test = {5,3,6,1,8};
	print_container(test.begin(),test.end());


	selection_sort<int,5>(test);
	print_container(test.begin(),test.end());


	std::array<int,5> test2 = {5,3,6,1,8};
	selection_sort(test2.begin(),test2.end());
	print_container(test2.begin(),test2.end());

	std::array<int,5> test3 = {5,3,6,1,8};
	buble_sort(test3.begin(),test3.end());
	print_container(test3.begin(),test3.end());

	std::array<int,5> test4 = {5,3,6,1,8};
	buble_sort<int,5>(test4);
	print_container(test4.begin(),test4.end());

	std::cout << "insertion sort" << std::endl;
	std::array<int,5> test5 = {5,3,6,1,8};
	insertion_sort<int,5>(test5);
	print_container(test5.begin(),test5.end());




	return 0;
}