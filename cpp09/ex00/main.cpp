
#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char** argv) {

	try {
		if (argc != 2) {
			throw RuntimeException("could not open file.");
		}
		BitcoinExchange btc;
		btc.evaluatePrice(argv[1]);
	}
	catch (const RuntimeException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
