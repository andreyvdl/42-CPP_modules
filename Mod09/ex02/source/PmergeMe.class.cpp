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
    _sDeq = that._sDeq;
    _sVec = that._sVec;
    _kDeq = that._kDeq;
    _kVec = that._kVec;
    _extra = that._extra;
  }
  return (*this);
}

/* METHODS ================================================================== */

#include "fordJohnson.template.tpp"

void  PmergeMe::fordJohnVec(std::vector<int>& arr)
{
  createPairs(_kVec, arr, _extra, (arr.size() % 2 ? true : false));
  determineLargerElement(_kVec);
  sortOnlyBiggers(_kVec.begin(), _kVec.end(), _sVec, _extra);
  insertLowest(_kVec, _sVec);
  binaryInsertion(_kVec, _sVec);
  arr = _sVec;
}

void  PmergeMe::fordJohnDeq(std::deque<int>& arr)
{
  createPairs(_kDeq, arr, _extra, (arr.size() % 2 ? true : false));
  determineLargerElement(_kDeq);
  sortOnlyBiggers(_kDeq.begin(), _kDeq.end(), _sDeq, _extra);
  binaryInsertion(_kDeq, _sDeq);
  arr = _sDeq;
}

