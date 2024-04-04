#include <vector>
#include <queue>
#include <iostream>

using namespace std;

template<class T>
class my_queue : public queue<T>
{
public:
	my_queue(vector<T> &v, size_t l, size_t r)
	{
		for(size_t i=l; i<=r; i++)
		{
			queue<T>::push(v[i]);
		}
	}

	T next()
	{
		T temp = queue<T>::front();
		queue<T>::pop();
		return temp;
	}

};


void merge(vector<int> &vect, size_t l, size_t r, size_t m)
{
	my_queue<int> b1 (vect,l,m);
	my_queue<int> b2 (vect,m+1,r);
	size_t i = l;
	while( !( b1.empty() ||  b2.empty() ) )
	{
		if(b1.front() <= b2.front())
		{
			vect[i++] = b1.next();
		}
		else 
		{
			vect[i++] = b2.next();
		}
	}

	while(!b1.empty())vect[i++]=b1.next();
	while(!b2.empty())vect[i++]=b2.next();
}

void merge_sort(vector<int> &vect, size_t l, size_t r)
{
	if(l<r)
	{
		size_t m = (l+r)/2;
		merge_sort(vect,l,m);
		merge_sort(vect,m+1,r);
		merge(vect,l,r,m);
	}
}




size_t get_next_pivot(vector<int> &v, size_t l, size_t r)
{
	auto p = r;
	auto fh = l;
	for(auto i = l; i < r ; i++)
	{
		if(v[i] < v[p])
		{
			swap(v[i],v[fh]);
			fh++;
		}
	}
	swap(v[fh],v[p]);
	return fh;
}

void quick_sort(vector<int> &v, size_t l, size_t r)
{
	if(l < r)
	{
		auto p =  get_next_pivot(v,l,r);
		if(p) quick_sort(v,l,p-1);
		quick_sort(v,p+1,r);
	}
}


int main()
{
	vector<int> test = {7,2,3,4,5,6,2,3,9,1};
    
	for_each(test.begin(),test.end(),print_l);
	cout << endl;

	merge_sort(test,0,test.size()-1);

	for_each(test.begin(),test.end(),print_l);
	cout << endl;

	vector<int> q_test = {7,2,3,4,5,6,2,3,9,1};
	quick_sort(q_test,0,q_test.size()-1);
	for_each(q_test.begin(),q_test.end(),print_l);
	cout << endl;

	return 0;
}