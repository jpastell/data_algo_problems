#include <iostream>
#include <vector>
#include <limits>
#include <optional>
#include <queue>
#include <deque>
using namespace std;


int get_next_pivot(vector<int> &s, int low, int high)
{
	auto p = high; //this is my pivot
	cout << "----- " << endl;
	for_each(s.begin(),s.end(),[](auto item) {cout << item << ",";});
	cout << endl;
	cout << "Pivot: " << p << endl;
	cout << "low:" << low << " high: " << high << endl;
	auto fh = low;
	for(auto i=low;i<high;i++)
	{
		cout << "i: " << i;
		cout << " fh: " << fh;
		cout << " s[fh]" << s[fh] ;
		cout << " s[i]" << s[i] ;
		cout << " s[p]: " << s[p] << endl;
		if(s[i] < s[p])
		{
			cout << " ++++ Bingo ++++" << endl;
			swap(s[i],s[fh]);
			fh++;
			for_each(s.begin(),s.end(),[](auto item) {cout << item << ",";});
			cout << endl;
			cout << " ++++++++" << endl;
		}
		cout << endl;
	}
	cout << "last: fh: " << fh << endl;
	swap(s[p],s[fh]);
	for_each(s.begin(),s.end(),[](auto item) {cout << item << ",";});
	cout << endl;
	return fh;
}

void quick_sort(vector<int> &s, int low, int high)
{
	if(low < high)
	{
		auto p = get_next_pivot(s,low,high);
		quick_sort(s,low,p-1);
		quick_sort(s,p+1,high);
	}
}



int main(void)
{
    vector<int> test = {7,2,3,4,9,6,2,3,1,5};
	// for_each(test.begin(),test.end(),[](auto item) {cout << item << ",";});
	// cout << endl;

    quick_sort(test,0,test.size()-1);

    // auto a  = get_next_pivot(test,0,test.size()-1);


	for_each(test.begin(),test.end(),[](auto item) {cout << item << ",";});
	cout << endl;

    return 0;
}