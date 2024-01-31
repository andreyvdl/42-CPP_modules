#include "../include/Span.class.hpp"
#include <iostream>
#include <limits>

// EXCEPTIONS =================================================================

const char* NotEnoughNbrExc::what() const throw()
{
  return ("Array has 0 or only 1 element!");
}

const char* LimitPassedExc::what() const throw()
{
  return ("Already at the limit of the array!");
}

// TRUCTORS ===================================================================

Span::Span(Span const& that): _sizeMax(0)
{
  *this = that;
}

Span::Span(unsigned int n): _sizeMax(n)
{
  _arr.reserve(_sizeMax);
}

Span::Span(void): _sizeMax(0) {};

Span::~Span(void) {};

// OPERATORS ==================================================================

Span& Span::operator=(Span const& that)
{
  if (this != &that) {
    _arr.reserve(that._sizeMax);
    _arr = that._arr;
    const_cast<unsigned int&>(_sizeMax) = that._sizeMax;
  }
  return (*this);
}

// METHODS ====================================================================

t_int64 Span::longestSpan(void)
throw (NotEnoughNbrExc)
{
  if (_sizeMax == 0 || _arr.size() <= 1) {
    throw NotEnoughNbrExc();
  }
  return (
    std::abs(
      *std::max_element(_arr.begin(), _arr.end())
      - *std::min_element(_arr.begin(), _arr.end())
    )
  );
}

t_int64 Span::shortestSpan(void)
throw (NotEnoughNbrExc)
{
  if (_sizeMax == 0 || _arr.size() <= 1) {
    throw NotEnoughNbrExc();
  }

  std::vector<int>::iterator tmp;
  std::vector<int>::iterator itB = _arr.begin();
  t_int64 shortest = std::numeric_limits<t_uint32>::max();

  for (tmp = itB++; tmp != _arr.end(); ++itB) {
    if (itB == _arr.end()) {
      itB = ++tmp;
      continue ;
    }
    shortest = std::abs(*tmp - *itB) < shortest ? std::abs(*tmp - *itB)
      : shortest; 
  }
  return (shortest);
}

void  Span::addNumber(int const nbr)
throw (LimitPassedExc)
{
  if (_sizeMax <= _arr.size()) {
    throw LimitPassedExc();
  }
  _arr.push_back(nbr);
}

void  Span::populate(std::vector<int>::iterator begin,
  std::vector<int>::iterator end
)
{
  try {
    while (begin != end) {
      addNumber(*begin++);
    }
  } catch (std::exception& e) {
    static_cast<void>(e);
  }
}

