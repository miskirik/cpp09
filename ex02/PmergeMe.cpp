#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(PmergeMe const &instance)
{
	*this = instance;
}

PmergeMe::~PmergeMe(void)
{
}

void PmergeMe::add_v(int n)
{
	if (n < 0)
		throw NegativeException();
	_v.push_back(n);
}

void PmergeMe::add_d(int n)
{
	if (n < 0)
		throw NegativeException();
	_d.push_back(n);
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
		_v = rhs._v;
		_d = rhs._d;
	}
	return (*this);
}

static void sort_vector_insertion(std::vector<int> &vec)
{
	int tmp;
	for (unsigned long i = 1; i < vec.size(); i++)
	{
		for (unsigned long j = i; j > 0; j--)
		{
			if (vec[j] < vec[j - 1])
			{
				tmp = vec[j];
				vec[j] = vec[j - 1];
				vec[j - 1] = tmp;
			}
			else
				break;
		}
	}
}

static void sort_deque_insertion(std::deque<int> &deq)
{
	int tmp;
	for (unsigned long i = 1; i < deq.size(); i++)
	{
		for (unsigned long j = i; j > 0; j--)
		{
			if (deq[j] < deq[j - 1])
			{
				tmp = deq[j];
				deq[j] = deq[j - 1];
				deq[j - 1] = tmp;
			}
			else
				break;
		}
	}
}

void PmergeMe::sort_v(void)
{
	std::setprecision(5);
	clock_t start = clock();
	std::vector<std::vector<int> > vec = merge_v();
	for (unsigned long i = 0; i < vec.size(); i++)
		sort_vector_insertion(vec[i]);
	
	for (unsigned long i = 1; i < vec.size(); i++)
	{
		for (unsigned long j = 0; j < vec[i].size(); j++)
			vec[0].push_back(vec[i][j]);
		
		sort_vector_insertion(vec[0]);
	}
	clock_t end = clock();
	double time_taken = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Vector size: " << vec[0].size()  << " Time taken by vector is : " << std::fixed 
        << time_taken; 
    std::cout << " microsecond " << std::endl; 
	std::cout << "Before: " << std::endl; 
	for (size_t i = 0; i < this->_v.size(); i++)
	{
		std::cout << this->_v[i];
		if (i < this->_v.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	std::cout << "After: " << std::endl; 
	for (size_t i = 0; i < vec[0].size(); i++)
	{
		std::cout << vec[0][i];
		if (i < vec[0].size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::sort_d(void)
{
	std::setprecision(5);
	clock_t start = clock();
	std::deque<std::deque<int> > deq = merge_d();
	for (unsigned long i = 0; i < deq.size(); i++)
		sort_deque_insertion(deq[i]);
	
	for (unsigned long i = 1; i < deq.size(); i++)
	{
		for (unsigned long j = 0; j < deq[i].size(); j++)
			deq[0].push_back(deq[i][j]);
		
		sort_deque_insertion(deq[0]);
	}
	clock_t end = clock();
	double time_taken = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Deque size: " << deq[0].size() << " Time taken by deque is : " << std::fixed 
        << time_taken; 
    std::cout << " microsecond " << std::endl;
	std::cout << "Before: " << std::endl;
	for (size_t i = 0; i < this->_d.size(); i++)
	{
		std::cout << this->_d[i];
		if (i < this->_d.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	std::cout << "After: " << std::endl; 
	for (size_t i = 0; i < deq[0].size(); i++)
	{
		std::cout << deq[0][i];
		if (i < deq[0].size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

std::vector<std::vector<int> > PmergeMe::merge_v(void)
{
	std::vector<std::vector<int> > vec;
	std::vector<int> tmp;
	for (unsigned long i = 0; i < _v.size();)
	{
		for (int k = 0; k < 5; k++)
		{
			if (i < _v.size())
				tmp.push_back(_v[i]);
			else
				break;
			i++;
		}
		vec.push_back(tmp);
		tmp.clear();
	}
	return (vec);
}

std::deque<std::deque<int> > PmergeMe::merge_d(void)
{
	std::deque<std::deque<int> > deq;
	std::deque<int> tmp;
	for (unsigned long i = 0; i < _d.size();)
	{
		for (int k = 0; k < 5; k++)
		{
			if (i < _d.size())
				tmp.push_back(_d[i]);
			else
				break;
			i++;
		}
		deq.push_back(tmp);
		tmp.clear();
	}
	return (deq);
}

const char *PmergeMe::NegativeException::what() const throw()
{
	return ("Error: Negative number");
}