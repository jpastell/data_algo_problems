#include <vector>
#include <optional>
#include <iostream>

using namespace std;

template <class T>
class min_heap
{


	inline optional<size_t> get_parent(size_t i)
	{
		optional<size_t> p = nullopt;
		if(i) p = i >> 1;
		return p;
	}

	inline size_t get_child_first_index(size_t i)
	{
		return (i << 1)+1;
	}

	void bubble_up(size_t i)
	{
		optional<size_t> p = nullopt;
		do
		{
			p = get_parent(i);
			if(p != nullopt)
			{
				if(container[i] < container[p.value()])
				{
					swap(container[i],container[p.value()]);
				} else {
					break;
				}
				i = p.value();
			}
		} while( p!= nullopt);
	}

	void buble_down()
	{
		//we start from the head
		size_t parent = 0;
		size_t min = parent;
		bool get_next = true;

		do
		{
			auto child_base = get_child_first_index(parent);
			for(auto i=0; i<2 ; i++)
			{
				child_base += i;
				if(child_base < count)
				{
					if(container[child_base] < container[parent])
					{
						swap(container[child_base],container[parent]);
						min = child_base;

					}
				}
			}

			if(parent != min)
			{
				parent = min;
			} else {
				get_next = false;
			}
	
		}while(get_next);
	}




public:

	void print()
	{
		for(auto item : container)
		{
			cout << item << ",";
		}
		cout << endl;
	}

	void insert(T t)
	{
		if(count < size)
		{
			count++;
			auto insert_idx = count-1;
			container[insert_idx] = t;
			bubble_up(insert_idx);
		}
	}

	optional<T> get_min()
	{
		optional<T> min = nullopt;
		if(count)
		{
			min = container[0];
			container[0] = container[count-1];
			count--;
			buble_down();
		}
		return min;
	}

	min_heap(size_t size):count{},size{size},container{}
	{
		container.resize(size);	
	}

	size_t count;
	size_t size;
	vector<T> container;
};

int main()
{
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
    cout << years.get_min().value() << endl;
    cout << years.get_min().value() << endl;
    cout << years.get_min().value() << endl;
    cout << years.get_min().value() << endl;
    cout << years.get_min().value() << endl;
    cout << years.get_min().value() << endl;
    years.print();
}