
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <fstream>

class BitcoinExchange {
	private:
		std::map<std::string, double> data;

	public:
		bool isNumber(const std::string & str);
		bool isDouble(const std::string & str);
		bool isLeapYear(int year);
		void checkKey(const std::string & key);
		void checkValue(double value);
		void evaluatePrice(char* fileName);
		void printData() const;

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

};

class RuntimeException : public std::runtime_error {
	public:
		RuntimeException(const std::string& message) : std::runtime_error(message) {}
};

#endif
