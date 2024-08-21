
#include "Span.hpp"
#include <vector>

int main()
{
	try {
		Span sp = Span(5);
		std::vector<int> containerVector;
		containerVector.push_back(3);
		containerVector.push_back(5);
		containerVector.push_back(8);
		containerVector.push_back(11);
		containerVector.push_back(-4);
		// containerVector.push_back(0);
		// sp.addNumber(6);
		// sp.addNumber(3);
		// sp.addNumber(17);
		// sp.addNumber(9);
		// sp.addNumber(11);
		sp.addNumbers(containerVector.begin(), containerVector.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
