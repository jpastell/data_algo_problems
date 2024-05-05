#include <vector>
#include <iostream>
#include <utility>

using namespace std;

bool finished = false;

bool is_a_solution(int k, int input)
{
	return (k==input);
}

void construct_candidates(vector<bool> &a, vector<bool> &c,int &ncc)
{
	c[0]=true;
	c[1]=false;
	ncc=2;
}

void process_solution(vector<bool> &a, int k, int input)
{
	cout << "{";
	for(int i =1; i <= k ; i++)
	{
		if(a[i])
		{
			cout << i << ",";
		}
	}
	cout << "}" << endl;
}


void bactrack(vector<bool> &a, int k, int input)
{
	vector<bool> candidates(a.size(),false);
	int next_candidate_count;


	cout << "k=" << k << " n=" << input << endl;

	cout << "a[1]=" << a[1] << " a[2]=" << a[2] << " a[3]="<< a[3] << endl;
	if(is_a_solution(k,input))
	{
		// process_solution(a,k,input);
		cout << "-----------" << endl;
	} else {
		k = k+1;
		construct_candidates(a,candidates,next_candidate_count);
		for(int i= 0 ; i < next_candidate_count; i++)
		{
			a[k] = candidates[i];
			// make_move(a,k,input);
			bactrack(a,k,input);
			// unmake_move(a,k,input);

			// if(finished)
			// {
			// 	return;
			// }
		}
	}
}


class Pattern_matching
{
	vector<vector<char>> &board;
	vector<char> &pattren;
	vector<pair<int,int>> solution;

	bool in_sol(pair<int,int> test)
	{
		auto it = find(solution.begin(),solution.end(),test);
		return (it != solution.end());
	}

	bool is_a_solution()
	{
		int i=0;
		for(auto coordinate : solution)
		{
			if(board[coordinate.first][coordinate.second] != pattren[i])
			{
				return false;
			}
			i++;
		}
		return true;
	}


	bool dfs(int row, int col, size_t length)
	{
		if(pattren.size() == length && is_a_solution())
		{
			print_solution();
			return true;
		}

		if( (row < 0) ||
			(col < 0) ||
			(row >= board.size()) ||
			(col >= board[0].size()) || 
			in_sol({row,col}) )
		{
			return false;
		}

		solution.push_back({row,col});
		bool result = 	dfs(row+1,col,length+1) ||
						dfs(row-1,col,length+1) ||
						dfs(row,col+1,length+1) ||
						dfs(row,col-1,length+1);
		solution.pop_back();
		return result;
		
	}

	bool find_path()
	{
		for(int i = 0; i < board.size(); i++)
		{
			for(int j= 0; j < board[0].size(); j++)
			{
				if(dfs(i,j,0))return true;
			}
		}
		return false;
	}


	void print_solution()
	{
		cout << "Solution size: " << solution.size() << endl;
		for(auto coordinate : solution)
		{
			cout << board[coordinate.first][coordinate.second];
		}

		cout << endl;
	}



public:
	Pattern_matching(vector<vector<char>> &board, vector<char> &pattren):
	board{board},pattren{pattren}
	{
	}

	void serach()
	{
		if(find_path())
		{
			cout << "solution found" << endl;
		} else {
			cout << "solution not found" << endl;
		}
	}

};


int main()
{

	//vector<bool> test(100,false);
	//bactrack(test,0,3);

	vector<vector<char>> board {{'a','p','o','z','k','y'},
								{'b','u','l','l','r','s'},
								{'i','a','o','o','u','a'}};

	vector<char> pattern = {'a','p','o','l','l','o'};


	Pattern_matching match {board,pattern};
	match.serach();


	// cout  << board[1][2]  << endl;


	return 0;
}