
#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span {
	private:
		unsigned int N;
		std::vector<int> data;

	public:

		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int num);
		void addNumbers(std::vector<int>::iterator it, std::vector<int>::iterator ite);
		unsigned int shortestSpan();
		unsigned int longestSpan();

		class AlreadyFullException : public std::exception {
			public:
				const char* what() const throw();
		};

		class FewNumberException : public std::exception {
			public:
				const char* what() const throw();
		};

};

#endif
