#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream fd("data.csv");
	if (fd.is_open())
	{
    	std::string line;
		std::getline(fd, line);
    	while (std::getline(fd, line)) {
        	addPrivate(line);
    }
    fd.close();
} else {
    std::cerr << "Wrong file!" << std::endl;
}
}

void BitcoinExchange::addPrivate(std::string line)
{
	std::string date;
	float		value;

	date = line.substr(0, 10);
	value = std::stof(line.substr(11, line.size()));

	this->data[date] = value;
}

void BitcoinExchange::compare(std::string input)
{
	if(input == "date | value")
		return ;
	if(checkInput(input))
		if(checkDate(input))
			compareDate(input);
}

bool BitcoinExchange::checkInput(std::string line)
{
	for(int i = 0; line[i]; i++)
	{
		if(i < 4)
			if(!isdigit(line[i]))
			{
				std::cout << "date error" << std::endl;
				return false;
			}

		if(i == 4)
			if(line[i] != '-')
			{
				std::cout << "date error" << std::endl;
				return false;
			}
		if(i > 4 && i < 7)
			if(!isdigit(line[i]))
			{
				std::cout << "date error" << std::endl;
				return false;
			}
		if(i == 7)
			if(line[i] != '-')
			{
				std::cout << "date error" << std::endl;
				return false;
			}
		if(i > 7 && i < 10)
			if(!isdigit(line[i]))
			{
				std::cout << "date error" << std::endl;
				return false;
			}
		if(i == 10)
			if(line[i] != ' ')
			{
				std::cout << "date error" << std::endl;
				return false;
			}
		if(i == 11)
			if(line[i] != '|')
			{
				std::cout << "date error" << std::endl;
				return false;
			}
		if(i == 12)
			if(line[i] != ' ')
			{
				std::cout << "date error" << std::endl;
				return false;
			}
		if(i == 13)
		{
			if(line[i] == '-')
			{
				std::cout << "Value must be positive" << std::endl;
				return false;
			}
			else if(!isdigit(line[i]))
			{
				std::cout << "date error" << std::endl;
				return false;
			}
		}
		if(i > 13)
			if(!isdigit(line[i]) && line[i] != '.')
			{
				std::cout << "value error" << std::endl;
				return false;
			}
	}
	if(line.size() < 13)
	{
		std::cout << "bad input"<< std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::checkDate(std::string line)
{
	int year, month, day;
	float value;
	year = stoi(line.substr(0, 4));
	month = stoi(line.substr(5, 7));
	day = stoi(line.substr(8, 10));
	value = stof(line.substr(13, line.size()));
	
	if(year < 2009 || year > 2022)
	{
		std::cout << "bad date" << std::endl;
		return false;
	}

	if(month < 1 || month > 12)
	{
		std::cout << "bad date" << std::endl;
		return false;
	}

	if(day < 1 || day > 31)
	{
		std::cout << "bad date" << std::endl;
		return false;
	}

	if(day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
	{
		std::cout << "bad date" << std::endl;
		return false;
	}

	if(day == 29 && month == 2 && year % 4 != 0)
	{
		std::cout << "bad date" << std::endl;
		return false;
	}

	if(day > 29 && month == 2)
	{
		std::cout << "bad date" << std::endl;
		return false;
	}
	if(value > 1000)
	{
		std::cout << "bad value" << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::compareDate(std::string line)
{
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	int year, month, day;
	float value;
	int id = 0;
	int im = 0;
	int iy = 0;
	unsigned long index = 0;

	year = stoi(line.substr(0, 4));
	month = stoi(line.substr(5, 7));
	day = stoi(line.substr(8, 10));
	value = stof(line.substr(13, line.size()));

	std::map<std::string, float>::iterator it;
	it = this->data.begin();

	while(index < this->data.size())
	{
        if((year - iy == stoi(it->first.substr(0, 4))) &&
			(month - im == stoi(it->first.substr(5, 7))) &&
			(day - id == stoi(it->first.substr(8, 10))))
		{
			std::cout << line.substr(0, 10) << " => " << value << " = " << value * it->second << std::endl;
			return ;
		}
		if(index == this->data.size() - 1)
			{
				index = 0;
				it = data.begin();
				if(day - id == 1)
				{
					if(month - im == 1)
					{
						day = 31;
						month = 12;
						im = 0;
						id = 0;
						iy++;
						continue;
					}
					else
					{
						day = 31;
						id = 0;
						im++;
						continue;
					}
				}
				else
				{
					id++;
					continue;
				}
			}
		index++;
		it++;
    }
	
}
