#pragma once
#ifndef MUTANT_STACK_TEMPLATE_HPP
# define MUTANT_STACK_TEMPLATE_HPP

# include <algorithm>
# include <stack>
# include <vector>

// ! K.I.S.S.
// # define GET_TYPE typename std::stack<T>::container_type
// # define MS_IT GET_TYPE::iterator

template <class T>
class MutantStack: public std::stack<T>
{
  public:
    MutantStack(void);
    MutantStack(MutantStack const& that);
    ~MutantStack(void);

    MutantStack<T>& operator=(MutantStack<T> const& that);

    // these ones are for access
    // stack::deque
    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator  begin(void);
    iterator  end(void);
};

# include "../source/MutantStack.template.tpp"

#endif
