
#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array {

	private:
		T* data;
		unsigned int length;

	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array& other);
		Array &operator = (const Array& other);

		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		unsigned int size() const;

		class IndexException : public std::exception {
			public:
				const char* what() const throw();
		};

};

#include "Array.tpp"

#endif
