#include <iostream>
#include <stack>
#include <list>
#include <algorithm>
#include <queue>
#include <optional>
#include <array>

#include <algorithm>

bool evaluate_expresion(char * expr)
{
	std::stack<char,std::list<char>> open {};
	// std::stack<char,std::list<char>> close {};
	std::cout << *expr << std::endl;
	while(*expr != '\0')
	{
		switch(*expr)
		{
			//Open cases
			case '(':
			case '{':
			case '[':
				open.push(*expr);
				break;
			//closing cases	
			case ')':
				if(open.top() == '(')
				{
					open.pop();
				}
				break;
			case '}':
				if(open.top() == '{')
				{
					open.pop();
				}
				break;
			case ']':
				if(open.top() == '[')
				{
					open.pop();
				}
				break;
			default:
				//No open no closing case
				break;
		}
		expr++;
	}
	if(open.size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

bool parenthesis_evaluation(char *expr, std::queue<char> &evaluation)
{
	std::stack<bool> exp_delimiter {};
	std::stack<char> exp_order {};
	bool valid_expresion = true;
	while(*expr != '\0')
	{
		if(*expr == '(')
		{
			exp_delimiter.push(true);
		}
		else if (*expr  == ')')
		{
			if(exp_delimiter.size() >= 1)
			{
				exp_delimiter.pop();
				if(exp_order.size() >= 1)
				{
					evaluation.push(exp_order.top());
					exp_order.pop();
				}
			}
			else
			{
				valid_expresion= false;
				break;
			}
		}
		else
		{
			exp_order.push(*expr);
		}
		expr++;
	}
	if(exp_order.size() == 1)
	{
		evaluation.push(exp_order.top());
		exp_order.pop();
	}

	if(exp_delimiter.size() != 0)
	{
		valid_expresion = false;
	}
	return valid_expresion;
}


bool expresion_delimiter(char *operation_ptr,
						std::queue<std::list<char>> &evaluation)
{
	int tracker = 0;
	bool valid_expression = true;
	bool new_expression = true;
	std::stack<std::list<char>> expression_stack;


	while(*operation_ptr != '\0')
	{
		std::cout << *operation_ptr;
		if(*operation_ptr == '(')
		{
			new_expression = true;
			tracker++;
		}
		else if (*operation_ptr == ')')
		{
			if(tracker >= 1)
			{
				//Valid expression
				tracker--;
				if(expression_stack.size() != 0 )
				{
					evaluation.push(expression_stack.top());
					expression_stack.pop();
				}
				else
				{
					//Invalid expression, empty parenthesis
					valid_expression = false;
					break;
				}
			}
			else
			{
				//Invalid expression clsoing parenthesis without
				//empty parenthesis
				valid_expression = false;
				break;
			}
		}
		else 
		{
			//check that the expression has valid characters
			if( (*operation_ptr >= '0' && *operation_ptr <= '9') || 
				*operation_ptr == '+' ||
				*operation_ptr == '-' || 
				*operation_ptr == '*' || 
				*operation_ptr == '/' || 
				*operation_ptr == '.' )
			{
				//Expression adition
				if(new_expression)
				{
					//Add a new item to the stack
					expression_stack.push(std::list<char> {*operation_ptr});
					new_expression = false;
				} else {
					(expression_stack.top()).push_back(*operation_ptr);
				}
			}
			else
			{
				valid_expression = false;
				break;
			}
		}
		operation_ptr++;
	}
	//Last element no parenthesis
	if(expression_stack.size() != 0 )
	{
		evaluation.push(expression_stack.top());
		expression_stack.pop();
	}
	std::cout << std::endl;
	return valid_expression;
}

/*
 * First element not * or /
 * 
 *
 *
 *
 */
// void eval_expression(std::list<char> &expression)
// {
// 	while(!expression.empty())
// 	{

// 	}
// }

std::optional<float> char_list_to_number(std::list<char> &list)
{
	//If the first item is a . just discarted we are just dealing with integers
	while(!list.empty() && list.back() == '.')
	{
		list.pop_back();
	}

	if(list.empty())
	{
		//Just dots error
		return std::nullopt;
	}
	else
	{
		float value = 0;
		float factor = 1;
		unsigned int number_count = 0;
		bool dot_found = false;
		//Continue with the processing
		while(!list.empty())
		{
			//We assume the number are integer until we find a .
			if(list.back() == '.')
			{
				if(dot_found == true)
				{
					//We already got a dot, error
					return std::nullopt;
				}
				else 
				{
					dot_found = true;
					//We need to calculate the divided factor
					float div_f = 1;
					for(unsigned int power = 0 ; power < number_count; power++)
					{
						div_f *= 10;
					}
					value = value/div_f;
					factor = 1;
				}
				list.pop_back();
			}
			else
			{
				value += ((list.back()-'0') * factor);
				factor *= 10;
				number_count++;
				list.pop_back();
			}
		}
		return value;
	}

}



int main(int argc, char* argv[])
{
	if( argc >= 2)
	{
		// std::queue<std::list<char>> evaluation {};
		// bool test = expresion_delimiter(argv[1],evaluation);
		// if(test)
		// {
		// 	std::cout << "Valid expression" << std::endl;
		// 	while(!evaluation.empty())
		// 	{
		// 		//Printing the list
		// 		//-----
		// 		auto temp = evaluation.front();
		// 		std::cout << "Expresion: " << std::endl;
		// 		while(!temp.empty())
		// 		{
		// 			std::cout << temp.front();
		// 			temp.pop_front();
		// 		}
		// 		std::cout << std::endl;
		// 		//---------
		// 		evaluation.pop();
		// 	}
		// }
		// else
		// {
		// 	std::cout << "Invalid expression" << std::endl;
		// }
		// 
		std::list<char> number {'1','2','3','.','5','4'};
		std::optional<float> f_number = char_list_to_number(number);
		std::cout << f_number.value() << std::endl;
	}
	else
	{
		std::cout << "invalid number of arguments" << std::endl;
	}
	return 0;
}