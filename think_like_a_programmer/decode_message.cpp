#include <iostream>
#include <optional>
#include <stack>

using std::cout;
using std::cin;
using std::endl;

static constexpr char UPPER_ANKER = ('A'-1);
static constexpr char LOWER_ANKER = ('a'-1);
static constexpr char PUNCT_ANKER = ('!'-1);


class Char_stack : public std::stack<char>
{
public:
	char pop ()
	{
		char temp = top();
		std::stack<char>::pop();
		return temp;
	}
};

enum class text_mode : char {upper=UPPER_ANKER, lower=LOWER_ANKER, punct=PUNCT_ANKER};

char translation(char mode, text_mode anker)
{
	return mode + static_cast<char>(anker);
}

text_mode next_mode(text_mode mode)
{
	switch(mode)
	{
		case text_mode::upper:
			return text_mode::lower;
		case text_mode::lower:
			return text_mode::punct;
		case text_mode::punct:
		default:
			return text_mode::upper;
	}
}

int convert_to_int(Char_stack &q_ref)
{
	int power = 1;
	int number = 0;
	while(!q_ref.empty())
	{
		char val = q_ref.pop();
		number += power * (val-'0');
		power *= 10;
	}
	return number;
}




void char_to_int()
{
	char input = cin.get();
	int modulus = 27;
	Char_stack s_num {};
	text_mode current_mode = text_mode::upper;
	if((input >= '0' && input <= '9') || input == '\n' || input == ',')
	{

		while(input != '\n')
		{
			//Process the number
			if(input ==  ',')
			{
				int int_val = convert_to_int(s_num);
				int cal_mod = int_val % modulus;

				if(cal_mod)
				{
					//cout.put(translation(mod,current_mode));
					char char_val = translation(cal_mod,current_mode);
					cout << " Int val: " << int_val << " char: "<< char_val <<endl;
				}
				else
				{
					current_mode = next_mode(current_mode);
					if(current_mode == text_mode::punct) modulus = 9;
					else modulus = 27;
				}
			} else {
				//Keep calulating
				s_num.push(input);

			}

			input = cin.get();
		}

		if(!s_num.empty())
		{
			int int_val = convert_to_int(s_num);
			int cal_mod = int_val % modulus;
			if(cal_mod != 0)
			{
				char char_val = translation(cal_mod,current_mode);
				cout << " Int val: " << int_val << " char: "<< char_val <<endl;
			}
		}

	}
}

void char_to_int_2()
{
	char input;
	int modulus = 27;
	text_mode current_mode = text_mode::upper;
	do
	{
		int number = 0;
		do
		{
			input = cin.get();
			if(input >= '0' && input <= '9')
			{
				//Keep calulating
				number = (number *10) + (input - '0');
			}
		}while(input >= '0' && input <= '9');

		if(input == '\n' || input == ',')
		{
			int cal_mod = number % modulus;
			if(cal_mod)
			{
				//cout.put(translation(mod,current_mode));
				char char_val = translation(cal_mod,current_mode);
				cout << " Int val: " << number << " char: "<< char_val <<endl;
			}
			else
			{
				current_mode = next_mode(current_mode);
				if(current_mode == text_mode::punct) modulus = 9;
				else modulus = 27;
			}
		}

	}
	while(input != '\n');

}

int main()
{
	char_to_int_2();
	return 0;
}