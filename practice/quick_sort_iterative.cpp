#include <vector>
#include <iostream>
#include <stack>

using namespace std;

size_t next_pivot(vector<int> &v, size_t l, size_t h)
{
	size_t fh = l;
	for(auto i = l; i < h ; i++)
	{
		if(v[i] < v[h])
		{
			swap(v[i],v[fh++]);
		}
	}
	swap(v[fh],v[h]);
	return fh;
}

void print(vector<int> &v)
{
	for(auto i:v)
	{
		cout << i << ",";
	}
	cout << endl;
}


void quick_sort(vector<int> &v, size_t l, size_t h)
{
	cout << "--------------" << endl;
	print(v);
	cout << "l=" << l << "h=" << h << endl; 
	if(l<h)
	{
		auto p = next_pivot(v,l,h);
		cout << "p=" << p << endl;
		quick_sort(v,l,p-1);
		quick_sort(v,p+1,h);
	}
	cout << "a--------------" << endl;
	cout << "l=" << l << "h=" << h << endl;
	cout << "a-------------a" << endl;
	print(v);
}

size_t get_kh_smallest(vector<int> &v)
{
	
}



int main()
{
	// vector<int> test = {7,2,3,4,5,6,2,3,9,1};
	// vector<int> test = {1,2,3,6,4};

	// cout << "FH="<< next_pivot(test,0,test.size()-1)<< endl;
	// print(test);
	vector<int> test = {7,8,3,1,5};
	cout << "FH="<< next_pivot(test,0,test.size()-1)<< endl;
	print(test);
	cout << "FH="<< next_pivot(test,0,2)<< endl;
	print(test);
	

	return 0;
}