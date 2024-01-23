#include <stdexcept>
#include <iostream>
#include "../include/Array.template.hpp"

template <typename T>
static void copyArray(T* dest, T* src, unsigned int size);

/* TRUCTORS ================================================================= */

TYPE
Array<T>::Array(void): _array(NULL), _size(0) {};

TYPE
Array<T>::Array(Array const& that):
_array(NULL), _size(0)
{
	*this = that;
}

TYPE
Array<T>::Array(unsigned int n):
_array(NULL), _size(n)
{
	if (n == 0) {
		return ;
	}
	_array = new T[n];
	for (unsigned int i = 0; i < n; i++) {
		_array[i] = T();
	}
}

TYPE
Array<T>::~Array(void)
{
	if (_array != NULL) {
		delete[] _array;
	}
}

/* OPERATORS ================================================================ */

TYPE
Array<T>& Array<T>::operator=(Array const& that)
{
	if (this != &that) {
		_size = that._size;
		if (_array != NULL) {
			delete[] _array;
		}
		if (that._array != NULL) {
			_array = new T[_size];
			copyArray<T>(_array, that._array, that._size);
		} else {
			_array = NULL;
		}
	}
	return (*this);
}

TYPE
T& Array<T>::operator[](unsigned int i) const
throw(std::out_of_range)
{
	if (_array == NULL) {
		throw std::out_of_range("Array is empty");
	}
	if (i >= _size) {
		throw std::out_of_range("Index out of range");
	}
	return (_array[i]);
}

/* METHODS ================================================================== */

TYPE
unsigned int Array<T>::size(void) const
{
	return (_size);
}

template <typename T>
static void copyArray(T* dest, T* src, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++) {
		dest[i] = src[i];
	}
}
