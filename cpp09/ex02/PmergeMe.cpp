
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char** argv) :  timeVector(0), timeList(0), timeDeque(0) {
	for (int i = 1; argv[i]; i++) {
		if (!isNumber(argv[i])) {
			throw AnyError();
		}
		dataVector.push_back(atoi(argv[i]));
		dataList.push_back(atoi(argv[i]));
		dataDeque.push_back(atoi(argv[i]));
	}
	for (unsigned long i = 0; i < dataVector.size(); i++) {
		for (unsigned long j = i + 1; j < dataVector.size(); j++) {
			if (dataVector[i] == dataVector[j]) {
				throw AnyError();
			}
		}
	}
}

bool PmergeMe::isNumber(char* str) {
	if (strlen(str) == 0) {
		return false;
	}
	if (str[0] == '0') {
		return false;
	}
	for (int i = 0; i < str[i]; i++) {
		if (str[i] < '0' || '9' < str[i]) {
			return false;
		}
	}
	return true;
}

void PmergeMe::sortVector(unsigned long span) {

	unsigned long chunk = dataVector.size() / span;

	// 음... 그러니까 span이 2면 2개씩 4면 4개씩
	for (unsigned long i = 0; i < chunk; i++) {
		if (dataVector[(i + 1) * span - 1 - span / 2] > dataVector[(i + 1) * span - 1]) {
			for (unsigned long j = i * span; j < i * span + span / 2; j++) {
				std::swap(dataVector[j], dataVector[j + span / 2]);
			}
		}
	}

	if (span * 2 <= dataVector.size()) {
		sortVector(span * 2);
	}
	// 이제 끼워 넣어야함

	// 홀수번이 메인체인
	// 2, 4, 6, 8 ... 얘네가 서브체인

	// 서브체인 메인체인 분리
	std::vector<int> mainChain;
	std::vector<int> subChain;
	int j = 0;
	for (unsigned long i = (span / 2) - 1; i < dataVector.size(); i += span / 2) {
		if (j % 2 == 0) {
			subChain.push_back(dataVector[i]);
		}
		else if (j % 2 == 1) {
			mainChain.push_back(dataVector[i]);
		}
		j++;
	}


	// 탐색해서 완성
	unsigned long tmp[3];
	tmp[0] = 1;
	tmp[1] = 3;
	tmp[2] = 3;
	mainChain.insert(mainChain.begin(), subChain[0]);
	for (unsigned long i = 1; i < subChain.size(); i++) {
		if (subChain.size() == 2) {
			std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), subChain[1]);
			mainChain.insert(it, subChain[1]);
		}
		else {
			std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), subChain[tmp[2] - 1]);
			mainChain.insert(it, subChain[tmp[2] - 1]);
		}
		tmp[2]--;
		if (tmp[2] == tmp[0]) {
			tmp[2] = tmp[1] + tmp[0] * 2;
			tmp[0] = tmp[1];
			tmp[1] = tmp[2];
		}
		if (tmp[2] > subChain.size()) {
			tmp[2] = subChain.size();
		}
	}


	// 이제 최신화
	std::vector<int> newVector;
	if (span > 2) {
		for (unsigned long i = 0; i < mainChain.size(); i++) {
			std::vector<int>::iterator it = std::find(dataVector.begin(), dataVector.end(), mainChain[i]);
			for (int k = span / 2 - 1; k > 0; k--) {
				newVector.push_back(*(it - k));
			}
			newVector.push_back(mainChain[i]);
		}
	}
	else {
		newVector = mainChain;
	}
	for (unsigned long i = 0; i < newVector.size(); i++) {
		dataVector[i] = newVector[i];
	}
}


std::list<int>::iterator PmergeMe::listIndex(std::list<int> & data, unsigned long index) {
	std::list<int>::iterator it = data.begin();
	std::advance(it, index);
	return it;
}

int PmergeMe::listIndexFornt(std::list<int>::iterator it, unsigned long index) {
	for (unsigned long i = 0; i < index; i++) {
		it--;
	}
	return *it;
}

void PmergeMe::sortList(unsigned long span) {

	unsigned long chunk = dataList.size() / span;

	int tmpNum;

	for (unsigned long i = 0; i < chunk; i++) {
		if (*listIndex(dataList, (i + 1) * span - 1 - span / 2) > *listIndex(dataList, (i + 1) * span - 1)) {
			for (unsigned long j = i * span; j < i * span + span / 2; j++) {
				// std::swap(listIndex(dataList, j), listIndex(dataList, j + span / 2));
				tmpNum = *listIndex(dataList, j);
				*listIndex(dataList, j) = *listIndex(dataList, j + span / 2);
				*listIndex(dataList, j + span / 2) = tmpNum;
			}
		}
	}

	if (span * 2 <= dataList.size()) {
		sortList(span * 2);
	}

	std::list<int> mainChain;
	std::list<int> subChain;
	int j = 0;
	for (unsigned long i = (span / 2) - 1; i < dataList.size(); i += span / 2) {
		if (j % 2 == 0) {
			subChain.push_back(*listIndex(dataList, i));
		}
		else if (j % 2 == 1) {
			mainChain.push_back(*listIndex(dataList, i));
		}
		j++;
	}

	unsigned long tmp[3];
	tmp[0] = 1;
	tmp[1] = 3;
	tmp[2] = 3;
	mainChain.insert(mainChain.begin(), *listIndex(subChain, 0));
	for (unsigned long i = 1; i < subChain.size(); i++) {
		if (subChain.size() == 2) {
			std::list<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), *listIndex(subChain, 1));
			mainChain.insert(it, *listIndex(subChain, 1));
		}
		else {
			std::list<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), *listIndex(subChain, tmp[2] - 1));
			mainChain.insert(it, *listIndex(subChain, tmp[2] - 1));
		}
		tmp[2]--;
		if (tmp[2] == tmp[0]) {
			tmp[2] = tmp[1] + tmp[0] * 2;
			tmp[0] = tmp[1];
			tmp[1] = tmp[2];
		}
		if (tmp[2] > subChain.size()) {
			tmp[2] = subChain.size();
		}
	}

	std::list<int> newList;
	if (span > 2) {
		for (unsigned long i = 0; i < mainChain.size(); i++) {
			std::list<int>::iterator it = std::find(dataList.begin(), dataList.end(), *listIndex(mainChain, i));
			for (int k = span / 2 - 1; k > 0; k--) {
				newList.push_back(listIndexFornt(it, k));
			}
			newList.push_back(*listIndex(mainChain, i));
		}
	}
	else {
		newList = mainChain;
	}
	for (unsigned long i = 0; i < newList.size(); i++) {
		*listIndex(dataList, i) = *listIndex(newList, i);
	}
}




void PmergeMe::sortDeque(unsigned long span) {

	unsigned long chunk = dataDeque.size() / span;

	for (unsigned long i = 0; i < chunk; i++) {
		if (dataDeque[(i + 1) * span - 1 - span / 2] > dataDeque[(i + 1) * span - 1]) {
			for (unsigned long j = i * span; j < i * span + span / 2; j++) {
				std::swap(dataDeque[j], dataDeque[j + span / 2]);
			}
		}
	}

	if (span * 2 <= dataDeque.size()) {
		sortDeque(span * 2);
	}

	std::deque<int> mainChain;
	std::deque<int> subChain;
	int j = 0;
	for (unsigned long i = (span / 2) - 1; i < dataDeque.size(); i += span / 2) {
		if (j % 2 == 0) {
			subChain.push_back(dataDeque[i]);
		}
		else if (j % 2 == 1) {
			mainChain.push_back(dataDeque[i]);
		}
		j++;
	}

	unsigned long tmp[3];
	tmp[0] = 1;
	tmp[1] = 3;
	tmp[2] = 3;
	mainChain.insert(mainChain.begin(), subChain[0]);
	for (unsigned long i = 1; i < subChain.size(); i++) {
		if (subChain.size() == 2) {
			std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), subChain[1]);
			mainChain.insert(it, subChain[1]);
		}
		else {
			std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), subChain[tmp[2] - 1]);
			mainChain.insert(it, subChain[tmp[2] - 1]);
		}
		tmp[2]--;
		if (tmp[2] == tmp[0]) {
			tmp[2] = tmp[1] + tmp[0] * 2;
			tmp[0] = tmp[1];
			tmp[1] = tmp[2];
		}
		if (tmp[2] > subChain.size()) {
			tmp[2] = subChain.size();
		}
	}

	std::deque<int> newDeque;
	if (span > 2) {
		for (unsigned long i = 0; i < mainChain.size(); i++) {
			std::deque<int>::iterator it = std::find(dataDeque.begin(), dataDeque.end(), mainChain[i]);
			for (int k = span / 2 - 1; k > 0; k--) {
				newDeque.push_back(*(it - k));
			}
			newDeque.push_back(mainChain[i]);
		}
	}
	else {
		newDeque = mainChain;
	}
	for (unsigned long i = 0; i < newDeque.size(); i++) {
		dataDeque[i] = newDeque[i];
	}
}

void PmergeMe::sortData() {
	std::cout << "Before: ";
	for (unsigned long i = 0; i < dataVector.size(); i++) {
		std::cout << dataVector[i] << " ";
	}
	std::cout << std::endl;

	time_t start, finish;

	start = clock();
	sortVector(2);
	finish  = clock();
	this->timeVector = (double)(finish - start) / 1000;

	start = clock();
	// sortList(2);
	finish  = clock();
	this->timeList = (double)(finish - start) / 1000;

	start = clock();
	sortDeque(2);
	finish  = clock();
	this->timeDeque = (double)(finish - start) / 1000;

	std::cout << "After: ";
	for (unsigned long i = 0; i < dataVector.size(); i++) {
		std::cout << dataVector[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of 5 elements with std::vector : " << this->timeVector << " us" << std::endl;
	std::cout << "Time to process a range of 5 elements with std::deque  : " << this->timeDeque << " us" << std::endl;
	// std::cout << "Time to process a range of 5 elements with std::list   : " << this->timeList << " us" << std::endl;
}

PmergeMe::PmergeMe() : timeVector(0), timeList(0), timeDeque(0) {}

PmergeMe::PmergeMe(const PmergeMe & other) : 
dataVector(other.dataVector), dataList(other.dataList), dataDeque(other.dataDeque), 
timeVector(other.timeVector), timeList(other.timeList), timeDeque(other.timeDeque) {}

PmergeMe & PmergeMe::operator=(const PmergeMe & other) {
	if (this != &other) {
		dataVector = other.dataVector;
		dataList = other.dataList;
		dataDeque = other.dataDeque;
		timeVector = other.timeVector;
		timeList = other.timeList;
		timeDeque = other.timeDeque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

const char* AnyError::what() const throw() {
	return "Error";
}
