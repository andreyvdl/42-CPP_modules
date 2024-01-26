#pragma once
#ifndef EASYFIND_TEMPLATE_HPP
# define EASYFIND_TEMPLATE_HPP

# include <iostream>
# include <stdexcept>
# include <algorithm>

class NotFoundExc: public std::exception
{
  public:
    virtual const char* what() const throw();
};

template <typename T>
typename T::iterator easyfind(T const& cont, int const val) throw(NotFoundExc);

# include "../source/easyfind.template.tpp"

#endif
