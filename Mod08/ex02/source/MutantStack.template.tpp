#include "../include/MutantStack.template.hpp"

// TRUCTORS ===================================================================

template <class T>
MutantStack<T>::MutantStack(void): std::stack<T>() {};

template <class T>
MutantStack<T>::MutantStack(MutantStack const& that): std::stack<T>()
{
  *this = that;
}

template <class T>
MutantStack<T>::~MutantStack(void) {};

// OPERATOR ===================================================================

template <class T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack const& that)
{
  if (this != &that) {
    std::stack<T>::operator=(that);
  }
  return (*this);
}

// METHODS ====================================================================

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
  return (this->c.begin());
}

template <class T>
typename MutantStack<T>::iterator  MutantStack<T>::end(void)
{
  return (this->c.end());
}
