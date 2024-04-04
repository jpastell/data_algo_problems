#include <iostream>
#include <vector>
#include <limits>
#include <optional>
#include <queue>
#include <deque>
using namespace std;

void merge(vector<int> &s, int low, int mid, int high)
{
	cout << "----- low:" << low  << " mid:" << mid << " high:" << high << endl;

	// auto middle_itr = s.begin()+(mid+1);
	deque<int> b1;//(s.begin(),middle_itr);
	deque<int> b2;//(middle_itr,s.end());
	for(auto i= low; i <= mid; i++) b1.push_front(s[i]);
	for(auto i= mid+1; i <= high; i++) b2.push_front(s[i]);

	for_each(b1.begin(),b1.end(),[](auto item) {cout << item << ",";}); cout << endl;
	for_each(b2.begin(),b2.end(),[](auto item) {cout << item << ",";}); cout << endl;

	// for_each(b1.begin(),b1.end(),[](auto item) {cout << item << ",";});
	// cout << endl;
	int i = low;
	while(!b1.empty() && !b2.empty()) {
		if(b1.back() <= b2.back()) {
			s[i++] = b1.back();
			b1.pop_back();
		} else {
			s[i++] = b2.back();
			b2.pop_back();
		}
	}

	//Add the buffers below
	while(!b1.empty())
	{
		s[i++] = b1.back();
		b1.pop_back();
	}

	//Add the buffers below
	while(!b2.empty())
	{
		s[i++] = b2.back();
		b2.pop_back();
	}

	for_each(s.begin(),s.end(),[](auto item) {cout << item << ",";});
	cout << endl << "----------------------------------" << endl;
}


void marge_sort(vector<int> &s, int low, int high)
{


	if(low < high)
	{
		int mid = (low + high)/2;
		// cout << "low:" << low  << " mid:" << mid << " high:" << high << endl;
		marge_sort(s,low,mid);
		marge_sort(s,mid+1,high);
	
		merge(s,low,mid,high);
	}
}


int main(void)
{
    vector<int> test = {7,2,3,4,5,6,2,3,9,1};
	for_each(test.begin(),test.end(),[](auto item) {cout << item << ",";});
	cout << endl;

    marge_sort(test,0,test.size()-1);

   // vector<int> myVector = {1, 2, 3, 4, 5};

   //  // Build an std::queue out of the std::vector
   //  deque<int> myQueue(myVector.begin(), myVector.end());
   //  
	for_each(test.begin(),test.end(),[](auto item) {cout << item << ",";});
	cout << endl;

    return 0;
}