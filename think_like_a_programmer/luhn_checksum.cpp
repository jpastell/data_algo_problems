#include <iostream>

using std::cout;
using std::cin;
using std::endl;

char double_char(char numerical_val)
{
	numerical_val *= 2;
	if(numerical_val >= 10)
	{
		numerical_val = 1 + (numerical_val - 10);
	}
	return numerical_val;
}

char get_numerical_value(char value)
{
	return value-'0';
}

bool validate_digit_number(char value)
{
	bool valid =  false;
	if(value >= '0' && value <= '9')
	{
		valid = true;
	}
	return valid;
}

bool valid_number(int sum)
{
	if(sum % 10)
	{
		return false;
	}
	else
	{
		return true;
	}
}


void get_input()
{
	cout << "Introduce the data followed by enter" << endl;
	char input  = cin.get();
	int sum = 0;
	bool double_val = false;
	while(validate_digit_number(input))
	{
		char numerical_val  = get_numerical_value(input);
		if(double_val)
		{
			sum += double_char(numerical_val);
		}
		else
		{
			sum += numerical_val;
		}
		input  = cin.get();
		double_val = !double_val;
	}
	if(valid_number(sum))
	{
		cout << "Number is valid" << endl;
	}
	else
	{
		cout << "Number is invalid" << endl;
	}
}


int main()
{
	get_input();
	return 0;
}