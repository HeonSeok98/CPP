
#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span& other) {
	this->N = other.N;
	this->data = other.data;
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		this->N = other.N;
		this->data = other.data;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
	if (data.size() == N) {
		throw AlreadyFullException();
	}
	data.push_back(num);
	std::sort(data.begin(), data.end());
}

void Span::addNumbers(std::vector<int>::iterator it, std::vector<int>::iterator ite) {
	while (it != ite) {
		if (data.size() == N) {
			throw AlreadyFullException();
		}
		data.push_back(*it);
		it++;
	}
	std::sort(data.begin(), data.end());
}

unsigned int Span::shortestSpan() {
	if (data.size() < 2) {
		throw FewNumberException();
	}
	unsigned int ans;
	ans = data[1] - data[0];
	for (size_t i = 0; i < data.size() - 1; i++) {
		ans = std::min<unsigned int>(ans, data[i + 1] - data[i]);
	}
	return ans;
}

unsigned int Span::longestSpan() {
	if (data.size() < 2) {
		throw FewNumberException();
	}
	return data.back() - data.front();
}

const char* Span::AlreadyFullException::what() const throw() {
	return "Already full...";
}

const char* Span::FewNumberException::what() const throw() {
	return "Few number...";
}
