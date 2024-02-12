#include "../include/RPN.class.hpp"

static void executeOperation(std::stack<ssize_t>& calc, char op)
  throw (std::domain_error);

// EXCEPTIONS =================================================================

const char* CalcMemExc::what(void) const throw()
{
  return ("Calculator memory is full! Please check how many numbers you have"
    " before an operator!"
  );
}

/* TRUCTORS ================================================================= */

RPN::RPN(void) {};

RPN::RPN(RPN const& that)
{
  *this = that;
}

RPN::~RPN(void) {};

/* OPERATORS ================================================================ */

RPN& RPN::operator=(RPN const& that)
{
  static_cast<void>(that);
  return (*this);
}

/* METHODS ================================================================== */

ssize_t RPN::calculate(std::string expr)
throw (std::domain_error, CalcMemExc)
{
  std::stack<ssize_t> calcMem;

  for (std::string::iterator it = expr.begin(); it != expr.end(); ++it) {
    if (isdigit(static_cast<int>(*it))) {
      calcMem.push(static_cast<ssize_t>(*it - '0'));
    } else {
      executeOperation(calcMem, *it);
    }
  }
  if (calcMem.size() != 1) {
    throw std::domain_error("Still have numbers! Check your input!");
  }
  return (calcMem.top());
}

static void executeOperation(std::stack<ssize_t>& calc, char op)
throw (std::domain_error)
{
  if (calc.size() < 2) {
    throw std::domain_error("Not enough numbers for an operation!");
  }

  ssize_t a, b = 0;

  b = calc.top();
  calc.pop();
  a = calc.top();
  calc.pop();

  switch (op) {
    case '+':
      calc.push(a + b);
      break;
    case '-':
      calc.push(a - b);
      break;
    case '*':
      calc.push(a * b);
      break;
    case '/':
      b == 0 ? throw std::domain_error("Division by zero!") : calc.push(a / b);
      break;
  }
}
