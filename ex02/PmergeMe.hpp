#ifndef PMERGEME_HPP
# define PMERGEME_HPP


#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>

class PmergeMe
{
	private:
		std::vector<int> _v;
		std::deque<int> _d;
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &instance);
		PmergeMe &operator=(PmergeMe const &rhs);
		~PmergeMe(void);
		void add_v(int n);
		void add_d(int n);
		void sort_v(void);
		void sort_d(void);
		std::vector< std::vector<int> > merge_v(void);
		std::deque< std::deque<int> > merge_d(void);

		class NegativeException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif