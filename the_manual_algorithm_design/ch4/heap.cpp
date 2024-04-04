#include <iostream>
#include <vector>
#include <limits>
#include <optional>
using namespace std;

template <typename T>
class min_heap {
public:
	min_heap(int size):container{},size{size},n{}
	{
		container.resize(size+1);
	}

	inline int get_parent(int i)
	{
		if(i == 1)
		{
			return -1;
		}
		else 
		{
			return i >> 1;
		}
	}

	inline int get_child(int i)
	{
		return (i << 1 );
	}

	void insert(T t)
	{
		if(n >= size)
		{
			cout << "LLeno" << endl;
		} else {
			n++;
			container[n] = t;
			bubble_up(n);
		}
	}

	void bubble_up(int n)
	{
		int parent = get_parent(n);
		
		if(parent == -1) return;

		if(container[parent] > container[n])
		{
			swap(container[parent],container[n]);
		}
		return bubble_up(parent);
	}

	void print()
	{
		for(int i = 1 ; i<=n; i++)
		{
			cout << container[i] << " ,";
		}
		cout << endl;
	}

	void bubble_down(int node)
	{
		int min_index = node; /*index of the lightest child*/
		int c = get_child(node);  /*child index*/
		for(int i = 0 ; i <= 1 ; i ++)
		{
			//Make sure inbound
			if((c + i) <= n)
			{
				if(container[min_index] > container[c + i])
				{
					min_index  = (c+i);
				}
			}
		}
		if(min_index != node)
		{
			swap(container[node],container[min_index]);
			bubble_down(min_index);
		}
	}

	optional<T> extract_min()
	{
		optional<T> my_opt = nullopt;
		if(n <= 0)
		{
			cout << "empty" << endl; 
		} else {
			my_opt = container[1];
			container[1] = container[n];
			n --;
			bubble_down(1);
		}
		return my_opt;
	}


private:
	vector<T> container;
	int size;
	int n;
};

int main(void){
    
    min_heap<int> years{10};
    years.insert(1918);
    years.insert(1804);
    years.insert(2001);
    years.insert(1941);
    years.insert(1865);
    years.insert(1783);
    years.insert(1492);
    years.insert(1776);
    years.insert(1945);
    years.insert(1963);
    years.print();
    cout << years.extract_min().value() << endl;
    cout << years.extract_min().value() << endl;
    years.print();
    return 0;
}