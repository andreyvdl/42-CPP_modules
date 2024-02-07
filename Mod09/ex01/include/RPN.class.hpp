#pragma once
#ifndef RPN_CLASS_HPP
# define RPN_CLASS_HPP

# include <iostream>
# include <stdexcept>
# include <cstdlib>
# include <stack>

class CalcMemExc: public std::exception
{
  public:
    virtual const char* what(void) const throw();
};

class RPN
{
  public:
    RPN(void);
    RPN(RPN const& that);
    ~RPN(void);

    RPN& operator=(RPN const& that);

    static ssize_t calculate(std::string expr)
      throw (std::domain_error, CalcMemExc);
};

#endif
