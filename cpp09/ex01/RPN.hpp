
#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>

class RPN {
	private:
		std::string line;
		std::stack<int> data;

	public:
		RPN(char* line);

		void calculate();

		class AnyErrorException : public std::exception {
			public:
				const char* what() const throw();
		};

		RPN();
		RPN(const RPN & other);
		RPN &operator=(const RPN & other);
		~RPN();

};

class BadInputException : public std::exception {
	public:
		const char* what() const throw();
};

#endif
