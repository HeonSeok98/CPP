
#include "PmergeMe.hpp"

int main(int argc, char** argv) {

	try {
		if (argc == 1) {
			throw AnyError();
		}
		PmergeMe pmergeMe(argv);

		pmergeMe.sortData();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
