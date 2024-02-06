#include "../include/BitcoinExchange.class.hpp"
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

static bool findDivisor(std::string& date, std::string::iterator& d1,
  std::string::iterator& d2
);
static bool has31Days(ssize_t month);
static bool hasOnlyDigits(std::string& sYear, std::string& sMonth,
  std::string& sDay
);
static bool isntLeapYear(ssize_t year);

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
  std::string::iterator d1;
  std::string::iterator d2;

  if (findDivisor(date, d1, d2) == false) {
    return (false);
  }

  std::string sYear(date.begin(), d1);
  std::string sMonth(d1 + 1, d2);
  std::string sDay(d2 + 1, date.end());

  if (hasOnlyDigits(sYear, sMonth, sDay) == false) {
    return (false);
  }

  std::istringstream iss(sYear);
  ssize_t iDay = -42;
  ssize_t iMonth = -42;
  ssize_t iYear = -42;

  iss.exceptions(std::ios::failbit);
  try {
    iss >> iYear;
  } catch (std::exception& e) {
    static_cast<void>(e);
    return (false);
  }
  iss.clear();
  iss.str(sMonth);
  try {
    iss >> iMonth;
  } catch (std::exception& e) {
    static_cast<void>(e);
    return (false);
  }
  iss.clear();
  iss.str(sDay);
  try {
    iss >> iDay;
  } catch (std::exception& e) {
    static_cast<void>(e);
    return (false);
  }
  if (iYear < 1 || iMonth < JAN || iMonth > DEC || iDay < 1 || iDay > 31) {
    return (false);
  }
  return (iDay <= (iMonth == FEB ? 
    (isntLeapYear(iYear) ? 28 : 29) :
    (has31Days(iMonth) ? 31 : 30))
  );
}

static bool findDivisor(std::string& date, std::string::iterator& d1,
  std::string::iterator& d2
)
{
  d1 = std::find(date.begin(), date.end(), '-');
  if (d1 == date.end()) {
    return (false);
  }
  d2 = std::find(d1 + 1, date.end(), '-');
  return (d2 != date.end() && std::find(d2 + 1, date.end(), '-') == date.end());
}

static bool hasOnlyDigits(std::string& sYear, std::string& sMonth,
  std::string& sDay
)
{
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
  return (true);
}

static bool isntLeapYear(ssize_t year)
{
  return ((year % 4 == 0 && year % 100 == 0 && year % 400 == 0) ||
    (year % 4 == 0 && year % 100 != 0)
  );
}

static bool has31Days(ssize_t month)
{
  return (month != APR && month != JUN && month != SEP && month != NOV);
}
