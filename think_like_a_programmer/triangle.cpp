#include <iostream>
#include <optional>


using std::cout;
using std::cin;
using std::endl;

void print_triangle_down()
{
	for(int c = 8; c > 8/2 ; c--)
	{
		// cout << c;
		int skip = 8 - c;
		// Skip in
		for(int space = 1 ; space <= skip ; space++)
		{
			cout << " ";
		}
		for(int r=skip; r < (8-skip) ; r++)
		{
			cout << "#";
		}
		// //skip out
		cout << endl;
	}
}

void print_trinagle_up()
{
	for(int c = 1; c <=4 ; c++)
	{
		// cout << c;
		int skip = 4 - c;
		// Skip in
		for(int space = 1 ; space <= skip ; space++)
		{
			cout << " ";
		}
		for(int r=skip; r < (8-skip) ; r++)
		{
			cout << "#";
		}
		// //skip out
		cout << endl;
	}
}


void print_star_up()
{
	for(int c = 1; c <=4 ; c++)
	{
		int empty_l;
		int draw_1;
		for(empty_l = 0  ; empty_l < c-1; empty_l++)
		{
			cout << "-";
		}

		for(draw_1  = 1  ; draw_1 <= c; draw_1++)
		{
			cout << "#";
		}

		// cout << " draw_1 "<<draw_1 << " empty_l " << empty_l;

		for(int mid  = 1  ; mid <= 14 - (2 * ((empty_l) + (draw_1-1))); mid++)
		{
			cout << "-";
		}

		for(draw_1  = 1  ; draw_1 <= c; draw_1++)
		{
			cout << "#";
		}
		// //skip out
		cout << endl;
	}
}

int main()
{
	print_star_up();
	// print_triangle_down();
	return 0;
}