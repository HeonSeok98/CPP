
#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <ctime>
#include <algorithm>
#include <cstring>


class PmergeMe {
	private:
		std::vector<int> dataVector;
		std::list<int> dataList;
		std::deque<int> dataDeque;

		double timeVector;
		double timeList;
		double timeDeque;

	public:
		PmergeMe(char** argv);

		bool isNumber(char* str);

		std::list<int>::iterator listIndex(std::list<int> & data, unsigned long index);
		int listIndexFornt(std::list<int>::iterator it, unsigned long index);

		void sortVector(unsigned long span);
		void sortList(unsigned long span);
		void sortDeque(unsigned long span);
		void sortData();

		PmergeMe();
		PmergeMe(const PmergeMe & other);
		PmergeMe & operator=(const PmergeMe & other);
		~PmergeMe();

};

class AnyError : public std::exception {
	public:
		const char* what() const throw();
};

#endif
