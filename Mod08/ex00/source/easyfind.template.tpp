#include "../include/easyfind.template.hpp"

template <typename T>
bool easyfind(T& cont, int const val)
{
  typename T::iterator itB = cont.begin();

  if (*itB == val) {
    return (true);
  }
  itB = std::find(itB, cont.end(), val);
  if (itB != cont.end()) {
    return (true);
  }
  return (false);
}
