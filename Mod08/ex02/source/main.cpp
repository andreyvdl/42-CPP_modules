#include "../include/defines.hpp"
#include "../include/MutantStack.template.hpp"
#include <list>
#include <iostream>
#include <stack>
#include <sstream>

namespace test
{
  void pdfTest(void)
  {
    std::cout << FG_BLUE "MUTANT STACK" RESET << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int> s(mstack);

    std::cout << std::endl << FG_BLUE "LIST" RESET << std::endl;

    std::list<int> mstack2;

    mstack2.push_back(5);
    mstack2.push_back(17);

    std::cout << mstack2.back() << std::endl;

    mstack2.pop_back();

    std::cout << mstack2.size() << std::endl;

    mstack2.push_back(3);
    mstack2.push_back(5);
    mstack2.push_back(737);
    //[...]
    mstack2.push_back(0);

    std::list<int>::iterator it2 = mstack2.begin();
    std::list<int>::iterator ite2 = mstack2.end();

    ++it2;
    --it2;
    while (it2 != ite2) {
      std::cout << *it2 << std::endl;
      ++it2;
    }
    std::stack< int, std::list<int> > s2(mstack2);
  }

  void copyTest(void)
  {
    MutantStack<int> mt;
    
    mt.push(42);
    mt.push(0);
    mt.push(-42);

    MutantStack<int> copy(mt);
    MutantStack<int> dup;

    copy.push(8);
    copy.push(16);
    copy.push(32);
    copy.push(64);
    dup = mt;

    std::sort(dup.begin(), dup.end());

    std::stringstream ss;

    ss << FG_BLUE "COPY" RESET ": { ";
    for (MutantStack<int>::iterator it = copy.begin(); it != copy.end();
      ++it
    ) {
      ss << *it;
      ss << (it + 1 == copy.end() ? "" : ", ");
    }
    std::cout << ss.str() << " }" << std::endl;

    ss.str(std::string());

    ss << FG_BLUE "DUP" RESET ": { ";
    for (MutantStack<int>::iterator it = dup.begin(); it != dup.end(); ++it) {
      ss << *it;
      ss << (it + 1 == dup.end() ? "" : ", ");
    }
    std::cout << ss.str() << " }" << std::endl;
  }
}

int main()
{
  std::cout << FG_YELLOW "PDF TEST" RESET << std::endl;
  test::pdfTest();
  std::cout << std::endl << FG_YELLOW "COPY TEST" RESET << std::endl;
  test::copyTest();
}
