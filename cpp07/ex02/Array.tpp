#include <cstdlib>

template <typename T>
Array<T>::Array(void) :
	_array(NULL),
	_size(0)
{}

template <typename T>
Array<T>::Array(std::size_t n) :
	_array(new T[n]),
	_size(n)
{}

template <typename T>
Array<T>::Array(const Array &other) :
    _array(new T[other._size]),
    _size(other._size)
{
	for (std::size_t i = 0; i < other._size; ++i) {
        _array[i] = other._array[i];
    }
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] this->_array;
		this->_size = other._size;
		this->_array = new T[other._size];
		for (std::size_t i = 0; i < _size; i++)
		{
			_array[i] = other._array[i];
		}
	}

	return (*this);
}

template <typename T>
T &Array<T>::operator[](std::size_t index)
{
	if (index >= _size)
		throw Array::OutOfBoundsIndexException();

	return (_array[index]);
}

template <typename T>
const char *Array<T>::OutOfBoundsIndexException::what(void) const throw()
{
	return ("Out of bound");
}
