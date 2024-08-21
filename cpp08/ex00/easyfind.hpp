
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& data, int value) {
	typename T::iterator it = find(data.begin(), data.end(), value);
	if ((*it) == value) {
		return it;
	}
	throw std::runtime_error("Value not found in container");
}

#endif
