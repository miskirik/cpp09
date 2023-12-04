#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <string>

class BitcoinExchange
{	
	private:
		std::map<std::string, float> data;
	public:
		BitcoinExchange();
		void addPrivate(std::string);
		void compare(std::string);
		bool checkInput(std::string line);
		bool checkDate(std::string);
		void compareDate(std::string);
};