#include <iostream>
#include <algorithm>

enum t_months
{
  JAN = 1,
  FEB,
  MAR,
  APR,
  MAY,
  JUN,
  JUL,
  AUG,
  SEP,
  OCT,
  NOV,
  DEC,
};

static bool isntLeapYear(long int year);

void removeWhitespace(std::string& line)
{
  size_t pos = line.find_first_not_of("\t ");
  
  if (pos != std::string::npos) {
    line.erase(0, pos);
  }
  pos = line.find_last_not_of("\t ");
  if (pos != std::string::npos && pos + 1 != line.size()) {
    line.erase(pos + 1);
  }
}

bool dateValid(std::string date)
{
  std::string::iterator d1 = std::find(date.begin(), date.end(), '-');

  if (d1 == date.end()) {
    return (false);
  }

  std::string::iterator d2 = std::find(d1 + 1, date.end(), '-');
  
  if (d2 == date.end()) {
    return (false);
  }

  std::string sYear(date.begin(), d1);
  std::string sMonth(d1 + 1, d2);
  std::string sDay(d2 + 1, date.end());
  int dayDigit = 0;
  int monthDigit = 0;

  for (std::string::iterator it = sYear.begin(); it != sYear.end(); ++it) {
    if (isdigit(static_cast<int>(*it)) == 0) {
       return (false);
    }
  }
  for (std::string::iterator it = sMonth.begin(); it != sMonth.end(); ++it) {
    if (isdigit(static_cast<int>(*it)) == 0) {
       return (false);
    }
    ++monthDigit;
  }
  for (std::string::iterator it = sDay.begin(); it != sDay.end(); ++it) {
    if (isdigit(static_cast<int>(*it)) == 0) {
       return (false);
    }
    ++dayDigit;
  }

  if (monthDigit != 2 || dayDigit != 2) {
    return (false);
  }
  
  long int iYear = atol(sYear.c_str());
  long int iMonth = atol(sMonth.c_str());
  long int iDay = atol(sDay.c_str());

  if (iMonth < JAN || iMonth > DEC || iDay < 0 || iDay > 31) {
    return (false);
  } else if (iDay == 29 && iMonth == FEB && isntLeapYear(iYear)) {
    return (false);
  } else if ((iDay == 30 || iDay == 31) && iMonth == FEB) {
    return (false);
  } else if ((iMonth == APR || iMonth == JUN || iMonth == SEP || iMonth == NOV)
    && iDay == 31
  ) {
    return (false);
  }
  return (true);
}

static bool isntLeapYear(long int year)
{
  if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0) {
    return (false);
  } else if (year % 4 == 0 && year % 100 != 0) {
    return (false);
  }
  return (true);
}
