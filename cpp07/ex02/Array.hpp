#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>
#include <exception>

template<typename T>
class Array
{
	public:
		Array<T>(void);
		Array<T>(std::size_t n);
		Array<T>(const Array &other);
		~Array<T>(void);

		Array	&operator=(const Array &other);
		T		&operator[](std::size_t index);

		class OutOfBoundsIndexException;

	private:
		T			*_array;
		std::size_t	_size;
};

template<typename T>
class Array<T>::OutOfBoundsIndexException : public std::exception
{
	public:
		const char *what() const throw();
};

# include "Array.tpp"

#endif
