
#include "BitcoinExchange.hpp"

bool BitcoinExchange::isNumber(const std::string & str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] < '0' || '9' < str[i]) {
			return false;
		}
	}
	return true;
}

bool BitcoinExchange::isDouble(const std::string & str) {
	int cnt = 0;
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == '.') {
			cnt++;
			if (i == 0 || i == str.length() - 1) {
				return false;
			}
		}
		else if ((str[i] < '0' || '9' < str[i])) {
			return false;
		}
	}
	if (cnt > 1) {
		return false;
	}
	return true;
}

bool BitcoinExchange::isLeapYear(int year) {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

void BitcoinExchange::checkKey(const std::string & key) {
	int year;
	int month;
	int day;

	if (key.length() != 10) {
		throw RuntimeException("bad input => " + key);
	}
	if (key[4] != '-' || key[7] != '-') {
		throw RuntimeException("bad input => " + key);
	}
	if (!isNumber(key.substr(0, 4)) || !isNumber(key.substr(5, 2)) || !isNumber(key.substr(8, 2))) {
		throw RuntimeException("bad input => " + key);
	}

	year = atoi(key.substr(0, 4).c_str());
	month = atoi(key.substr(5, 2).c_str());
	day = atoi(key.substr(8, 2).c_str());
	if (month < 1 || 12 < month) {
		throw RuntimeException("bad input => " + key);
	}
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		if (day < 1 || 31 < day) {
			throw RuntimeException("bad input => " + key);
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day < 1 || 30 < day) {
			throw RuntimeException("bad input => " + key);
		}
	}
	else {
		if (isLeapYear(year)) {
			if (day < 1 || 29 < day) {
				throw RuntimeException("bad input => " + key);
			}
		}
		else {
			if (day < 1 || 28 < day) {
				throw RuntimeException("bad input => " + key);
			}
		}
	}
}

void BitcoinExchange::checkValue(double value) {
	if (value <= 0) {
		throw RuntimeException("not a positive number.");
	}
	if (value >= 1000) {
		throw RuntimeException("too large a number.");
	}
}

void BitcoinExchange::evaluatePrice(char* fileName) {
	std::ifstream inFile(fileName);
	if (!inFile) {
		throw RuntimeException("could not open file.");
	}
	std::string line;
	std::string key;
	double value;
	char* end;
	std::getline(inFile, line);
	if (line != "date | value") {
		throw RuntimeException("bad file.");
	}
	while (std::getline(inFile, line)) {
		try {
			size_t pos = 0;
			if ((pos = line.find(" | ", pos)) != std::string::npos) {
				key = line.substr(0, pos);
				checkKey(key);
				if (line[pos + 3] == '-') {
					throw RuntimeException("not a positive number.");
				}
				if (!isDouble(line.substr(pos + 3))) {
					throw RuntimeException("bad input => " + line);
				}
				value = strtod(line.substr(pos + 3).c_str(), &end);
				checkValue(value);
				std::map<std::string, double>::iterator it = data.lower_bound(key);
				if (it == data.begin() && it->first > key) {
					throw RuntimeException("bad input => " + line);
				}
				if (it->first > key) {
					it--;
				} 
				std::cout << key << " => " << value << " = " << it->second * strtod(line.substr(pos + 3).c_str(), &end) << std::endl;
			}
			else {
				throw RuntimeException("bad input => " + line);
			}
		}
		catch (const RuntimeException& e) {
			std::cerr << "Error: " << e.what()<< std::endl;
		}
	}
}

void BitcoinExchange::printData() const {
	std::map<std::string, double>::const_iterator it;
	for (it = data.begin(); it != data.end(); ++it) {
		std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
	}
}

BitcoinExchange::BitcoinExchange() {

	std::string key;
	double value;

	std::ifstream inFile("data.csv");
	if (!inFile) {
		throw RuntimeException("could not open file.");
	}
	std::string line;
	char* end;
	std::getline(inFile, line);
	if (line != "date,exchange_rate") {
		throw RuntimeException("bad file.");
	}
	while (std::getline(inFile, line)) {
		size_t pos = 0;
		if ((pos = line.find(",", pos)) != std::string::npos) {
			key = line.substr(0, pos);
			checkKey(key);
			if (!isDouble(line.substr(pos + 1))) {
				throw RuntimeException("bad input => " + line);
			}
			value = strtod(line.substr(pos + 1).c_str(), &end);
			data[key] = value;
		}
	}
	if (data.empty()) {
		throw RuntimeException("bad file.");
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : data(other.data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		this->data = other.data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

