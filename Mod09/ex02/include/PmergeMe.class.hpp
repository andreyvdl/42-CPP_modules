#pragma once
#ifndef P_MERGE_ME_CLASS_HPP
# define P_MERGE_ME_CLASS_HPP

# include <algorithm>
# include <deque>
# include <iostream>
# include <utility>
# include <vector>

class PmergeMe
{
  private:
    std::vector< std::pair<int, int> >  _kVec;
    std::vector<int>                    _sVec;
    std::deque< std::pair<int, int> >   _kDeq;
    std::deque<int>                     _sDeq;
    std::pair<bool, int>                _extra;

  public:
    PmergeMe(void);
    PmergeMe(PmergeMe const& that);
    ~PmergeMe(void);

    PmergeMe& operator=(PmergeMe const& that);

    void  fordJohnVec(std::vector<int>& arr);
    void  fordJohnDeq(std::deque<int>& arr);
};

#endif
