#include "../include/defines.hpp"
#include "../include/Span.class.hpp"
#include <iostream>

namespace test
{
  void pdfTest(void)
  {
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }

  void validTest(void)
  {
    Span sp(3);
    Span sp2;
    std::vector<int> vec;

    vec.push_back(32);
    vec.push_back(64);
    vec.push_back(16);
    sp.populate(vec.begin(), vec.end());

    sp2 = sp;

    Span sp3(sp2);

    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp3.longestSpan() << std::endl;

    Span tenK(10000);

    std::cout << FG_CYAN "This is gonna take some time..." RESET << std::endl;
    for (int i = 0; i < 10000; ++i) {
      tenK.addNumber(i + i);
    }
    std::cout << tenK.shortestSpan() << std::endl;
    std::cout << tenK.longestSpan() << std::endl;
  }

  void invalidTest(void)
  {
    Span sp;

    try {
      sp.addNumber(-42);
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }

    try {
      sp.longestSpan();
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }

    Span sp2(1);

    sp2.addNumber(0);
    try {
      sp.shortestSpan();
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
}

int main(void)
{
  std::cout << FG_YELLOW "PDF TEST" RESET << std::endl;
  test::pdfTest();
  std::endl(std::cout);
  std::cout << FG_YELLOW "VALID TEST" RESET << std::endl;
  test::validTest();
  std::endl(std::cout);
  std::cout << FG_YELLOW "INVALID TEST" RESET << std::endl;
  test::invalidTest();
}

