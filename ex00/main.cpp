#include "BitcoinExchange.hpp"

int main(int ac, char **ag)
{
	if(ac != 2)
	{
		std::cout << "Wrong argument!!!" << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	std::ifstream input(ag[1]);
	if (input.is_open())
	{
		std::string line;
    	while (std::getline(input, line))
    			btc.compare(line);
    	input.close();
	}
	else
	{
    	std::cerr << "input file warning!!!" << std::endl;
		return 2;
	}
	return 0;
}