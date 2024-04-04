#include <vector>
#include <optional>
#include <iostream>

using namespace std;


template<typename T>
class min_heap
{
	size_t size;
	size_t count;
	vector<T> container;

	inline optional<size_t> get_parent_idx(size_t idx)
	{
		optional<size_t> p_idx = nullopt;
		if(idx != 0)
			p_idx = idx >> 1;
		return p_idx;
	}

	inline size_t get_child_base_idx(size_t idx)
	{
		return idx << 1;
	}

	void bubble_up(size_t idx)
	{
		optional<size_t> p_idx = get_parent_idx(idx);
		//Base case
		if(p_idx == nullopt) return;

		//Actuall buble up
		if(container[p_idx.value()] > container[idx])
		{
			swap(container[p_idx.value()],container[idx]);
		}
		bubble_up(p_idx.value());
	}

	void bubble_down(size_t idx)
	{
		size_t min_idx = idx;
		size_t child_idx = get_child_base_idx(idx);


		for(int i =0 ; i<=1 ; i++)
		{
			size_t t_idx = child_idx +i;
			if(t_idx <= count)
			{
				//in bound
				if(container[t_idx] < container[min_idx])
				{
					min_idx = t_idx;
				}
			}
		}
		if(min_idx != idx)
		{
			swap(container[idx],container[min_idx]);
			bubble_down(min_idx);
		}
	}

public:

	min_heap(size_t size):size{size},count{},container{}
	{
		container.resize(size);
	}


	void print()
	{
		for(auto item:container)
		{
			cout << item << ",";
		}
		cout << endl;
	}

	void insert(T t)
	{
		if(count >= size)
		{
			cout << "Full" << endl;
		} else {
			container[count] = t;
			bubble_up(count);
			count++;
		}

	}

	optional<T> extract_min()
	{
		optional<T> my_min = nullopt;
		if(count != 0)
		{
			my_min = container[0];
			container[0] = container[count-1];
			count--;
			bubble_down(0);
		}
		return my_min;
	}

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
    cout << years.extract_min().value() << endl;
    cout << years.extract_min().value() << endl;
    cout << years.extract_min().value() << endl;
    cout << years.extract_min().value() << endl;
    cout << years.extract_min().value() << endl;
    cout << years.extract_min().value() << endl;
    years.print();
	return 0;
}