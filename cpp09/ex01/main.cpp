
#include "RPN.hpp"
#include <iostream>

int main(int argc, char** argv) {

	try {
		if (argc != 2) {
			throw BadInputException();
		}
		RPN rpn(argv[1]);

		rpn.calculate();

	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
