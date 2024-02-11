#include <deque>
#include <iostream>
#include <vector>
#include <ctime>

#include "mergeSort.template.tpp"
#include "insertionSort.template.tpp"
#include "../include/PmergeMe.class.hpp"

#define CLOCKS_PER_MS 1000

/*
 * TODO:
 * use argv as input numbers
 */

int main(void)
{
  std::vector<int> sortIt;
  PmergeMe ford;

  sortIt.push_back(5);
  sortIt.push_back(-4);
  sortIt.push_back(5);
  sortIt.push_back(3);
  sortIt.push_back(-4);
  sortIt.push_back(3);
  sortIt.push_back(5);
  sortIt.push_back(-4);
  std::cout << "Before sorting: ";
  for (std::vector<int>::iterator it = sortIt.begin(); it != sortIt.end(); ++it) {
    std::cout << *it << " ";
  }
  std::endl(std::cout);
  clock_t start = clock();
  ford.fordJohnVec(sortIt);
  clock_t end = clock();
  std::cout << "After sorting:  ";
  for (std::vector<int>::iterator it = sortIt.begin(); it != sortIt.end(); ++it) {
    std::cout << *it << " ";
  }
  std::endl(std::cout);
  std::cout << "time: " << double(end - start) / CLOCKS_PER_MS << "ms" << std::endl;
  return (0);
}
