
#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {

	std::vector<int> containerVector;
	containerVector.push_back(3);
	containerVector.push_back(5);
	containerVector.push_back(8);
	containerVector.push_back(11);
	containerVector.push_back(-4);

	std::list<int> containerList;
	containerList.push_back(13);
	containerList.push_back(-5);
	containerList.push_back(0);
	containerList.push_back(1);
	containerList.push_back(-3);

	try {
		std::cout << *easyfind(containerVector, 11) << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << *easyfind(containerVector, 111) << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << *easyfind(containerList, 0) << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << *easyfind(containerList, 3) << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
