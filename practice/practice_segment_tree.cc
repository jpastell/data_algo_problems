#include <vector>
#include <iostream>

using namespace std;


inline int leaft(vector<int> &array,int node)
{
	return((array[node] > array[node+1])?1:0); 
}

inline int branch_action(vector<int> &tree, int left, int right)
{

	if(tree[left])
		return tree[left] + tree[right];
	else
		//this means the left is not bigger than anything
		return tree[left];
}

inline int get_mid(int left, int right)
{
	return (left + ((right-left)/2));
}

void build_tree(vector<int> &array, vector<int> &tree, int node, int left, int right)
{

	if(left == right)
	{
		tree[node] = leaft(array,left);
		cout << "node=" << node << ", val=" << tree[node] << ", left=" << left<< endl;
	} else {
		// mind point between left and rigth
		int mid  = get_mid(left,right);
		int node_double = node *2;
		int new_left = node_double + 1;
		int new_right = node_double + 2;
		//build the left side
		build_tree(array,tree,new_left,left,mid);
		//build the right side
		build_tree(array,tree,new_right,mid+1,right);
		tree[node] = branch_action(tree,new_left,new_right);
	}

}

int query_tree(vector<int> &tree, int curr ,int left, int right, int q_l, int q_r)
{
	//Out of range
	if( q_l > right || q_r < left)
	{
		//return something does not mess with the query
		return 0;
	}

	//in range
	if( left >= q_l && right <= q_r)
	{
		return tree[curr];
	}

	//partial
	int mid = get_mid(left,right);
	int node_double = curr *2;
	int new_left = node_double+1;
	int new_right = node_double+2;
	int seg_left = query_tree(tree,new_left,left,mid,q_l,q_r);
	int seg_right = query_tree(tree,new_right,mid+1,right,q_l,q_r);
	return seg_left + seg_right;
}

void print(vector<int> &vec)
{
	for(auto s : vec)
	{
		cout << s << ",";
	}
	cout << endl;
}


int main ()
{
	vector<int> arr_less = {5,2,6,1};
	print(arr_less);
	vector<int> seg_tree ((arr_less.size()<<1),-1);
	print(seg_tree);
	build_tree(arr_less,seg_tree,0,0,arr_less.size()-2);
	print(seg_tree);

	cout << query_tree(seg_tree,0,0,arr_less.size()-2,0,2) << endl;
	cout << query_tree(seg_tree,0,0,arr_less.size()-2,1,2) << endl;
	cout << query_tree(seg_tree,0,0,arr_less.size()-2,2,2) << endl;

	//Output: [2,1,1,0]

	return 0;
}