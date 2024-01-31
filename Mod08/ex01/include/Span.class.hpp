#pragma once
#ifndef SPAN_CLASS_HPP
# define SPAN_CLASS_HPP

# include <algorithm>
# include <vector>
# include <stdexcept>

typedef long long int           t_int64;
typedef unsigned int            t_uint32;
typedef unsigned long long int  t_uint64;

class NotEnoughNbrExc: public std::exception
{
  public:
    virtual const char* what() const throw();
};

class LimitPassedExc: public std::exception
{
  public:
    virtual const char* what() const throw();
};

class Span
{
  private:
    std::vector<int>  _arr;
    const t_uint32    _sizeMax;

  public:
    Span(Span const& that);
    Span(unsigned int n);
    Span(void);
    ~Span(void);

    Span& operator=(Span const& that);

    t_int64   longestSpan(void) throw(NotEnoughNbrExc);
    t_int64   shortestSpan(void) throw(NotEnoughNbrExc);
    void      addNumber(int const nbr) throw(LimitPassedExc);
    void      populate(std::vector<int>::iterator begin,
      std::vector<int>::iterator end
    );
};

#endif
