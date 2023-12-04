#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:
		std::stack<int> _stack;
	public:
		RPN(std::string str);
		RPN(RPN const &src);
		RPN &operator=(RPN const &rhs);
		~RPN(void);
		void check(std::string str);
};

#endif