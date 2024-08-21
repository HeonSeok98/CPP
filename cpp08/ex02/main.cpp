
#include "MutantStack.hpp"

int main() {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "----------------------------" << std::endl;

	MutantStack<int> mstack2(mstack);
	mstack2.push(10);
	mstack2.push(20);
	mstack2.push(30);
	MutantStack<int>::iterator it2 = mstack2.begin();
	MutantStack<int>::iterator ite2 = mstack2.end();
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}

	std::cout << "----------------------------" << std::endl;

	MutantStack<int> mstack3;
	mstack3 = mstack;
	mstack3.pop();
	mstack3.pop();
	mstack3.pop();
	MutantStack<int>::iterator it3 = mstack3.begin();
	MutantStack<int>::iterator ite3 = mstack3.end();
	while (it3 != ite3)
	{
		std::cout << *it3 << std::endl;
		++it3;
	}

	return 0;
}