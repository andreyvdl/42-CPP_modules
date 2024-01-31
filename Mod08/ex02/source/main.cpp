#include "../include/MutantStack.template.hpp"
#include <list>
#include <iostream>
#include <stack>

int main()
{
  std::cout << "TEST MUTANT" << std::endl;
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

  std::cout << std::endl << "TEST LIST" << std::endl;

  std::list<int> mstack2;

  mstack2.push_back(5);
  mstack2.push_back(17);

  // pela logica LIFO (Last-IN, First-OUT) aqui eh back e pop_back
  // ao inves de front e pop_front
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
  return 0;
}
