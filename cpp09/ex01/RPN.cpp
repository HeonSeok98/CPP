
#include "RPN.hpp"

RPN::RPN(char* line) : line(std::string(line)) {}

void RPN::calculate() {
	int tmp1;
	int tmp2;

	for (unsigned long i = 0; i < line.length(); i++) {
		if (i % 2 == 1) {
			if (line[i] != ' ') {
				throw AnyErrorException();
			}
		}
		else {
			if ('0' <= line[i] && line[i] <= '9') {
				data.push(line[i] - '0');
			}
			else if (line[i] == '+' || line[i] == '-' || line[i] == '*') {
				if (data.size() < 2) {
					throw AnyErrorException();
				}
				tmp1 = data.top();
				data.pop();
				tmp2 = data.top();
				data.pop();
				if (line[i] == '+') {
					data.push(tmp1 + tmp2);
				}
				else if (line[i] == '-') {
					data.push(tmp2 - tmp1);
				}
				else if (line[i] == '*') {
					data.push(tmp1 * tmp2);
				}
			}
			else if (line[i] == '/') {
				if (data.size() < 2) {
					throw AnyErrorException();
				}
				tmp1 = data.top();
				if (tmp1 == 0) {
					throw AnyErrorException();
				}
				data.pop();
				tmp2 = data.top();
				data.pop();
				data.push(tmp2 / tmp1);
			}
			else {
				throw AnyErrorException();
			}
		}
	}
	if (data.size() != 1) {
		throw AnyErrorException();
	}
	std::cout << data.top() << std::endl;
}

const char* RPN::AnyErrorException::what() const throw() {
	return "Error";
}

RPN::RPN() {}

RPN::RPN(const RPN & other) : line(other.line) {}

RPN& RPN::operator=(const RPN & other) {
	if (this != &other) {
		this->line = other.line;
	}
	return *this;
}

RPN::~RPN() {}

const char* BadInputException::what() const throw() {
	return "Bad Input!";
}
