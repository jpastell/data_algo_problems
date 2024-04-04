#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int leaf_action(vector<int> &arr, size_t curr_idx)
{
	return (arr[curr_idx] > arr[curr_idx+1])? 1:0;
}

void branch_action(vector<int> &st, vector<int> &arr, size_t curr, size_t left, size_t right)
{
	st[curr] = st[left] + st[right];
}

void st_build(vector<int> &st, vector<int> &arr, size_t curr, size_t left, size_t right)
{
	if(left == right)
	{
		st[curr]=leaf_action(arr,left);
	} else{
		size_t mid = left + ((right-left)/2);
		size_t curr_double = curr *2;
		size_t left_idx = curr_double + 1;
		size_t right_idx = curr_double + 2;
		//left node build
		st_build(st,arr,left_idx,left,mid);
		//right node build 
		st_build(st,arr,right_idx,mid+1,right);
		//We add the element in the sub-set
		branch_action(st,arr,curr,left_idx,right_idx);
	}
}


int st_query(vector<int> &st,
			size_t curr_node_idx,
			size_t left_range,
			size_t riht_range, 
			size_t q_left, 
			size_t q_right)
{

	cout << "curr_node_idx: " << curr_node_idx << "----"<< endl;
	cout << "left_range: " << left_range << endl;
	cout << "riht_range: " << riht_range << endl;
	cout << "q_left: " << q_left << endl;
	cout << "q_right: " << q_right << endl;

	//Case 2 : index out or range
	if(  riht_range < q_left || left_range > q_right )
	{
		cout << "case 2---"<< endl;
		return 0;
	}
	

	//Case 1: inside the range 
	if(left_range >= q_left && riht_range <= q_right)
	{
		cout << "case 1---"<< endl;
		return st[curr_node_idx];
	}



	cout << "case 3---"<< endl;
	//Case 3: partially inside a range
	size_t mid = left_range + (riht_range-left_range)/2;
	size_t left_child_idx = (2*curr_node_idx)+1;
	size_t right_child_idx = (2*curr_node_idx)+2;
	int leftMin = st_query(st,left_child_idx,left_range,mid,q_left,q_right);
	int rightMin = st_query(st,right_child_idx,mid+1,riht_range,q_left,q_right);
	return leftMin + rightMin;
}

//Min query
void build_st_tree(vector<int> &st, vector<int> &arr, size_t curr_node_idx, size_t left, size_t right)
{

	cout << "curr_node_idx: " << curr_node_idx << endl;
	cout << "left: " << left << endl;
	cout << "right: " << right << endl;

	//Leaf
	if(right == left)
	{
		st[curr_node_idx] = arr[left];
	}
	else
	{
		size_t mid = left + (right-left)/2;
		size_t left_child_idx = (2*curr_node_idx)+1;
		size_t right_child_idx = (2*curr_node_idx)+2;
		//Build the left - child to the left is (2*index)+1
		build_st_tree(st,arr,left_child_idx,left,mid);
		//Build the right - hild to the left is (2*index)+2
		build_st_tree(st,arr,right_child_idx,mid+1,right);
		//build index add the value of the to the current no in idx
		if(st[right_child_idx] < st[left_child_idx])
		{
			st[curr_node_idx] = st[right_child_idx];
		}
		else
		{
			st[curr_node_idx] = st[left_child_idx];
		}
	}
}

int query(vector<int> &st,
			size_t curr_node_idx,
			size_t left_range,
			size_t riht_range, 
			size_t left, 
			size_t right)
{

	cout << "curr_node_idx: " << curr_node_idx << endl;
	cout << "left_range: " << left_range << endl;
	cout << "riht_range: " << riht_range << endl;

	//Case 1: inside the range
	if(left <= left_range && riht_range <= right)
	{
		cout << "case 1---"<< endl;
		return st[curr_node_idx];
	}

	//Case 2 : index out or range
	if(right < left_range || left > riht_range)
	{
		cout << "case 2---"<< endl;
		return numeric_limits<int>::max();
	}

	cout << "case 3---"<< endl;
	//Case 3: partially inside a range
	size_t mid = left_range + (riht_range-left_range)/2;
	size_t left_child_idx = (2*curr_node_idx)+1;
	size_t right_child_idx = (2*curr_node_idx)+2;
	int leftMin = query(st,left_child_idx,left_range,mid,left,right);
	int rightMin = query(st,right_child_idx,mid+1,riht_range,left,right);
	if(leftMin < rightMin) return leftMin;
	else return rightMin;
}


size_t determine_st_size(size_t n)
{
	size_t k=1, i=0;
	while(k<n)
	{
		k = 1<<i++;
	}
	if(n == k)
	{
		return ((n << 1) -1);
	} else {
		//s is not a power of 2, at this point
		//k is the next power of 2 bigger than n
		return ((k<<1)-1);
	}
}


void print_vec(vector<int> &v)
{
	cout << "Printing vector" << endl;
	for(auto item : v)
    {
    	cout<<item<<",";
    }
    cout<<endl;
}


int main(void){
    
    // vector<int> arr = {5,3,1};
    // vector<int> st (determine_st_size(arr.size()),0);
    // cout << "Min: " << endl;
    // build_st_tree(st,arr,0,0,arr.size()-1);
	// print_vec(st);
    // cout << "Min: " << query(st,0,2,2,0,arr.size()-1) << endl;

  
    vector<int> arr_less = {5,3,1,2};
    size_t arr_size_to_cover = arr_less.size()-1;
    size_t tree_size = determine_st_size(arr_size_to_cover);
    vector<int> st_less (tree_size,-1);
    st_build(st_less,arr_less,0,0,arr_size_to_cover-1);
    print_vec(st_less);


    // cout << "Range: " << st_query(st_less,0,0,2,0,2) << endl;
    
    cout << "Range: " << st_query(st_less,0,0,2,1,2) << endl;
    
    // cout << "Range: " << st_query(st_less,0,0,2,2,2) << endl;

    return 0;
}