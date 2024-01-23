#pragma once
#ifndef ITER_TEMPLATE_HPP
# define ITER_TEMPLATE_HPP

# include <cstdlib>

template <typename T>
void iter(T const* arrAddr, int size, void (*func)(T const&))
{
	if (arrAddr == NULL || func == NULL) {
		return ;
	}
	for (int i = 0; i < size; i++) {
		func(arrAddr[i]);
	}
}

template <typename T>
void iter(T* arrAddr, int size, void (*func)(T&))
{
	if (arrAddr == NULL || func == NULL) {
		return ;
	}
	for (int i = 0; i < size; i++) {
		func(arrAddr[i]);
	}
}

#endif
