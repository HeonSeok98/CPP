#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : data(NULL), length(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : length(n) {
	if (length > 0) {
		data = new T[length];
		for (unsigned int i = 0; i < length; i++) {
			data[i] = T();
		}
	} else {
		data = NULL;
	}
}

template <typename T>
Array<T>::Array(const Array& other) : length(other.length) {
	if (length > 0) {
		data = new T[length];
		for (unsigned int i = 0; i < length; ++i) {
			data[i] = other.data[i];
		}
	} else {
		data = NULL;
	}
}

template <typename T>
Array<T>::~Array() {
	delete[] data;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		delete[] data;
		length = other.length;
		if (length > 0) {
			data = new T[length];
			for (unsigned int i = 0; i < length; ++i) {
				data[i] = other.data[i];
			}
		} else {
			data = NULL;
		}
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= length) {
		throw IndexException();
	}
	return data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= length) {
		throw IndexException();
	}
	return data[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return length;
}

template <typename T>
const char* Array<T>::IndexException::what() const throw() {
	return "Index out of range!";
}

#endif
