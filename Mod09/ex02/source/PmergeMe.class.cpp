#include "../include/PmergeMe.class.hpp"

/* TRUCTORS ================================================================= */

PmergeMe::PmergeMe(void) {};

PmergeMe::PmergeMe(PmergeMe const& that)
{
  *this = that;
}

PmergeMe::~PmergeMe(void) {};

/* OPERATORS ================================================================ */

PmergeMe& PmergeMe::operator=(PmergeMe const& that)
{
  if (this != &that) {
    static_cast<void>(that);
  }
  return (*this);
}

/* METHODS ================================================================== */

