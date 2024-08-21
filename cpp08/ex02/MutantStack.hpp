
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
	private:

	public:
		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;

		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;

		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator = (const MutantStack& other);
		virtual ~MutantStack();

};

#include "MutantStack.tpp"

#endif
