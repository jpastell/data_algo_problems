#include <vector>
#include <limits>
#include <iostream>


//std::numeric_limits<int>::min();

using namespace std;
constexpr int int_limit = numeric_limits<int>::min(); 


int find_max_range(vector<int> &v)
{

	int mid = (v.size()) >> 1;
	int sum =0;
	int max_left = int_limit;
	int max_rigth = int_limit;

	for(int i = mid; i >=0 ; i--)
	{
		sum += v[i];
		if(sum > max_left) max_left = sum;
	}

	sum = 0;
	for(int i = mid+1; i < v.size(); i++)
	{
		sum += v[i];
		if(sum > max_rigth) max_rigth = sum;
	}

	return max_left + max_rigth;
}


int main()
{
	// vector<int> data {-17,5,3,-10,6,1,4,-3,8,1,-13,4};

	vector<int> data {2, 3, 4, 5, 7};

	// vector<int> data {1,5,3,-10,20,-1};




	auto information = find_max_range(data);
	cout << information << endl;
	return 0;
}
