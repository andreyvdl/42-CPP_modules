#include "../include/easyfind.template.hpp"

const char* NotFoundExc::what() const throw()
{
  return ("Value not found");
}

template <typename T>
typename T::iterator easyfind(T& cont, int const val)
throw(NotFoundExc)
{
  typename T::iterator itB = cont.begin();
  typename T::iterator itE = cont.end();

  if (*itB == val) {
    return (itB);
  }
  itB = std::find(itB, itE, val);
  if (itB != itE) {
    return (itB);
  }
  throw NotFoundExc();
}
