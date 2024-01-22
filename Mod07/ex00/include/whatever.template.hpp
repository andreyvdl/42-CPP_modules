#pragma once
#ifndef WHATEVER_TEMPLATE_HPP
# define WHATEVER_TEMPLATE_HPP

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T const &a, T const &b)
{
	return (a < b ? a : b);
}

template <typename T>
T max(T const &a, T const &b)
{
	return (::min(a, b) == a ? b : a);
}

#endif
