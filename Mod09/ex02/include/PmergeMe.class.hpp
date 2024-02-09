/**
 * File              : PmergeMe.class.hpp
 * Author            : adantas- <adantas-@student.42sp.org.br>
 * Date              : 2024/02/08
 * Last Modified Date: 2024/02/08
 */

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
