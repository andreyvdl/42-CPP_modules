#include "../include/easyfind.template.hpp"
#include "../include/defines.hpp"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <list>

namespace tests
{
  void dequeTest(void)
  {
    std::deque<int> deck;
    std::stringstream ss;

    deck.push_back(1);
    deck.push_front(3);
    deck.push_back(2);
    deck.push_front(4);
    deck.push_back(5);

    std::cout << FG_CYAN "CONTENT:" RESET << std::endl;
    ss << "Deque: ";
    for (size_t i = 0; i < deck.size(); i++) {
      ss << deck[i] << " ";
    }
    std::cout << ss.str() << std::endl;

    try {
      std::cout << FG_BLUE "SEARCHING FOR 2" RESET << std::endl;
      std::cout << *easyfind(deck, 2) << std::endl;
      std::cout << FG_RED "SEARCHING FOR A VALUE THAT DON'T EXIST" RESET
        << std::endl;
      std::cout << *easyfind(deck, -42) << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }

  void listTest(void)
  {
    std::list<int> lst;
    std::stringstream ss;

    lst.push_back(1);
    lst.push_front(3);
    lst.push_back(2);
    lst.push_front(4);
    lst.push_back(5);

    std::cout << FG_CYAN "CONTENT:" RESET << std::endl;
    ss << "List: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++) {
      ss << *it << " ";
    }
    std::cout << ss.str() << std::endl;

    try {
      std::cout << FG_BLUE "SEARCHING FOR 2" RESET << std::endl;
      std::cout << *easyfind(lst, 2) << std::endl;
      std::cout << FG_RED "SEARCHING FOR A VALUE THAT DON'T EXIST" RESET
        << std::endl;
      std::cout << *easyfind(lst, -42) << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }

  void vectorTest(void)
  {
    std::vector<int> vec;
    std::stringstream ss;

    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(5);

    std::cout << FG_CYAN "CONTENT:" RESET << std::endl;
    ss << "Vector: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
      ss << *it << " ";
    }
    std::cout << ss.str() << std::endl;

    try {
      std::cout << FG_BLUE "SEARCHING FOR 2" RESET << std::endl;
      std::cout << *easyfind(vec, 2) << std::endl;
      std::cout << FG_RED "SEARCHING FOR A VALUE THAT DON'T EXIST" RESET
        << std::endl;
      std::cout << *easyfind(vec, -42) << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
}

int main(void)
{
  std::cout << FG_YELLOW "DEQUE TEST" RESET << std::endl;
  tests::dequeTest();
  std::endl(std::cout);
  std::cout << FG_YELLOW "LIST TEST" RESET << std::endl;
  tests::listTest();
  std::endl(std::cout);
  std::cout << FG_YELLOW "VECTOR TEST" RESET << std::endl;
  tests::vectorTest();

  return (0);
}
