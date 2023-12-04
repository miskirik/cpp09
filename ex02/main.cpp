#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "usage: ./PmergeMe \" argument \" " << std::endl;
		return (1);
	}
	try
	{
		PmergeMe pmergeme;
		for (int i = 1; i < argc; i++)
		{
			std::string str(argv[i]);
			for(int j = 0; str[j]; j++)
				if(isdigit(str[j]) == 0)
					throw std::exception();
			pmergeme.add_v(std::stoi(str));
			pmergeme.add_d(std::stoi(str));
		}
		pmergeme.sort_v();
		pmergeme.sort_d();
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: Argument must be integer and positive" << std::endl;
	}
	return (0);
}


//Elimin güzelliği tşkr <3 - ALP/Ifmai