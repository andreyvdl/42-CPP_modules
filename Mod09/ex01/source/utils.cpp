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

void removeSpaces(std::string& str)
{
  std::string newStr = "";

  for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
    if (*it != ' ') {
      newStr += *it;
    }
  }
  str = newStr;
}
