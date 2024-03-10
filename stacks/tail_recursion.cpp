#include <iostream>

double pow(double base, unsigned int power)
{
	if(power == 0)
	{
		return 1;
	}
	else
	{
		return base * pow(base, power-1);
	}
}

unsigned int fibonacci(unsigned int n = 0)
{
	if(n == 0)
	{
		return 0;
	}
	else if ( n <=2 )
	{
		return 1;
	} else {
		return fibonacci(n-1) + fibonacci(n-2);
	}

}

unsigned int fibonacci_iter(unsigned int n)
{
	unsigned int fibo = 0, fibo_2 = 0, fibo_1 = 1;
	if(n == 0)
	{
		return fibo_2;
	}
	else
	{
		for(unsigned int i = 2; i <= n ;i++)
		{
			fibo = fibo_1 + fibo_2;
			fibo_2 = fibo_1;
			fibo_1 = fibo;
		}
		return fibo_1;
	}

}

unsigned int fibonacci_tail(unsigned int n,
							unsigned int fibo_2 = 0,
							unsigned int fibo_1 = 1)
{
	if(n == 0)
	{
		std::cout << "--" << std::endl;
		std::cout << "n0:"<< n << " ";
		std::cout << "n-1:"<< fibo_1 << " ";
		std::cout << "n-2:"<< fibo_2 << std::endl;
		std::cout << "--" << std::endl;
		return fibo_2;
	} else {
		std::cout << "--" << std::endl;
		std::cout << "n:"<< n << " ";
		std::cout << "n-1:"<< fibo_1 << " ";
		std::cout << "n-2:"<< fibo_2 << std::endl;
		std::cout << "--" << std::endl;
		return fibonacci_tail(n-1,fibo_1,fibo_1 + fibo_2);
	}

}


unsigned int tail_loop(unsigned int i, unsigned int index=0)
{
	if(i == 0)
	{
		std::cout << "--" << std::endl;
		std::cout << "i0:"<< i << " ";
		std::cout << "index"<< index << std::endl;
		return index;
	} else {
		std::cout << "--" << std::endl;
		std::cout << "i:"<< i << " ";
		std::cout << "index"<< index << std::endl;
		return tail_loop(i-1,index+2);
	}
}

unsigned int head_loop(unsigned int i)
{
	unsigned int index=i;
	if(i == 0)
	{
		std::cout << "----" << std::endl;
		std::cout << "i:"<< i << " ";
		std::cout << "index "<< index << std::endl;
		return index;
	} else {
		std::cout << "--" << std::endl;
		std::cout << "i:"<< i << " ";
		std::cout << "index "<< index << std::endl;
		head_loop(i-1);
		std::cout << "index after call i= " << i  << " index= "<< index << std::endl;
		return index;
	}
}

double pow_head(double base, unsigned int power)
{
 	double context  = base;

	if(power == 0)
	{
		std::cout << "----" << std::endl;
		std::cout << "power:"<< power << " ";
		std::cout << "base:"<< base << " ";
		std::cout << "context "<< context << std::endl;
		return context;
	}
	else
	{
		std::cout << "---" << std::endl;
		std::cout << "power:"<< power << " ";
		std::cout << "base:"<< base << " ";
		std::cout << "context "<< context << std::endl;
		pow_head(base*context, power-1);
		std::cout << "---after---" << std::endl;
		std::cout << "power:"<< power << " ";
		std::cout << "base:"<< base << " ";
		std::cout << "context "<< context << std::endl;
		return context;
	}
}



int main(int argc, char *agrv[])
{
	std::cout << fibonacci(0) << std::endl;
	std::cout << fibonacci(1) << std::endl;
	std::cout << fibonacci(2) << std::endl;
	std::cout << fibonacci(7) << std::endl;

	std::cout << fibonacci_iter(0) << std::endl;
	std::cout << fibonacci_iter(1) << std::endl;
	std::cout << fibonacci_iter(2) << std::endl;
	std::cout << fibonacci_iter(7) << std::endl;


	// std::cout << fibonacci_tail(0) << std::endl;
	// std::cout << fibonacci_tail(1) << std::endl;
	// std::cout << fibonacci_tail(2) << std::endl;
	std::cout << head_loop(3) << std::endl;

}