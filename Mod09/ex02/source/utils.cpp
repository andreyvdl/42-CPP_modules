#include "../include/PmergeMe.class.hpp"
#include <ctime>
#include <iostream>

void removeWhitespaces(std::string& str)
{
  size_t pos = str.find_first_not_of("\t ");

  str.erase(0, pos);
  pos = str.find_last_not_of("\t ");
  if (std::string::npos != pos) {
    str.erase(pos + 1);
  }
}

bool isSorted(std::vector<int>& arr)
{
  for (std::vector<int>::iterator it = arr.begin() + 1; it != arr.end(); ++it) {
    if (*it < *(it - 1)) {
      return (false);
    }
  }
  return (true);
}
