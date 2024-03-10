#include <iostream>

void reverse_string()
{
	char input = std::cin.get();
	if(input != '\n')
	{
		reverse_string();
		std::cout.put(input);
	}
}


int main(int argc, char *agrv[])
{
	std::cout << "Input the string to reverse foolowed by enter: " << std::endl;
	reverse_string();

}