#pragma once
#ifndef P_MERGE_ME_CLASS_HPP
# define P_MERGE_ME_CLASS_HPP

class PmergeMe
{
  public:
    PmergeMe(void);
    PmergeMe(PmergeMe const& that);
    ~PmergeMe(void);

    PmergeMe& operator=(PmergeMe const& that);
};

#endif
