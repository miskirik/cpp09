#include "RPN.hpp"

// 0 a bölümü handle et

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./RPN \"expression\"" << std::endl;
		return (1);
	}
	std::string str(av[1]);
	try
	{
		RPN rpn(str);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	return (0);
}
