#include "RPN.hpp"

//https://isaaccomputerscience.org/concepts/dsa_toc_rpn?examBoard=all&stage=all

RPN::RPN(std::string str)
{
	check(str);
	std::stack<int> stack;
	int a;
	int b;
	int result;

	for(size_t i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
			stack.push(str[i] - '0');
		else if (str[i] == '+' && stack.size() > 1)
		{
			a = stack.top();
			stack.pop();
			b = stack.top();
			stack.pop();
			result = a + b;
			stack.push(result);
		}
		else if (str[i] == '-' && stack.size() > 1)
		{
			a = stack.top();
			stack.pop();
			b = stack.top();
			stack.pop();
			result = b - a;
			stack.push(result);
		}
		else if (str[i] == '*' && stack.size() > 1)
		{
			a = stack.top();
			stack.pop();
			b = stack.top();
			stack.pop();
			result = a * b;
			stack.push(result);
		}
		else if (str[i] == '/' && stack.size() > 1)
		{
			a = stack.top();
			stack.pop();
			b = stack.top();
			stack.pop();
			if (a == 0)
				throw std::invalid_argument("Division by zero");
			result = b / a;
			stack.push(result);
		}
		else if(str[i] != ' ' && !isdigit(str[i]))
			throw std::invalid_argument("Too much operator");
	}
	if(stack.size() != 1)
		throw std::invalid_argument("Too much number");
	else
		std::cout << stack.top() << std::endl;
}

RPN::RPN(RPN const &src)
{
	*this = src;
}

RPN::~RPN(void)
{}

RPN &	RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return (*this);
}

void	RPN::check(std::string str)
{
	for(size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]) && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != ' ')
			throw std::invalid_argument("Error");
	}
	int j = 0;
	for(size_t i = 0; i < str.length(); i++)
	{
		if(str[i] == ' ')
			j++;
		if(j == (int)str.size() )
			throw std::invalid_argument("Error");
	}
	if(str.size() == 0)
		throw std::invalid_argument("Error");
	if(str.find('+') == std::string::npos && str.find('-') == std::string::npos && str.find('/') == std::string::npos && str.find('*') == std::string::npos)
		throw std::invalid_argument("Error");
}