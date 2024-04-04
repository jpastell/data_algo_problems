#include <stack>
#include <iostream>

using namespace std;

int count_max_parentehsis(char *c_string)
{
	int max = 0;
	stack<char> counter;
	while(*c_string !='\0')
	{
		if(*c_string == '(')
		{
			counter.push('(');
		} else {
			//get the size of the stack
			int size =  counter.size();
			if (size > max) max = size;
			if(!counter.empty())
			{
				counter.pop();
			}
		}
		c_string++;
	}
	return max;
}


int main(int arcgc, char * argv[])
{
	cout << *argv[1] << endl;
	cout << count_max_parentehsis(argv[1]) << endl;
	return 0;
}

