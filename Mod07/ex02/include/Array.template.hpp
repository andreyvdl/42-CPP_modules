#pragma once
#ifndef ARRAY_TEMPLATE_HPP
# define ARRAY_TEMPLATE_HPP

# define TYPE template <class T>

template <class T>
class Array
{
	private:
		T*				_array;
		unsigned int	_size;

	public:
		Array(void);
		Array(Array const& that);
		Array(unsigned int n);
		~Array(void);

		Array&	operator=(Array const& that);
		T&		operator[](unsigned int i) const
			throw(std::out_of_range);

		unsigned int	size(void) const;
};

# include "../source/Array.template.tpp"

#endif
