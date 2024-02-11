#include <deque>
#include <iostream>
#include <vector>
#include <ctime>

#include "mergeSort.template.tpp"
#include "insertionSort.template.tpp"

#define CLOCKS_PER_MS 1000

/*
 * TODO:
 * Implement Ford-Jonhson of wikipedia
 * Test wikipedia Ford-Jonhson
 * Implement Ford-Johnson of stackExchange
 * Test stackExchange Ford-Johnson
 * Implement Ford-Johnson of G2G
 * Test G2G Ford-Johnson
 * Implement Ford-Johnson of IQ
 * Test IQ Ford-Johnson
 * use argv as input numbers
 */

int main(void)
{
  std::vector<int> sortIt;

  sortIt.push_back(5);
  sortIt.push_back(-4);
  sortIt.push_back(3);
  sortIt.push_back(-2);
  sortIt.push_back(1);
  sortIt.push_back(0);
  std::cout << "Before sorting: ";
  for (std::vector<int>::iterator it = sortIt.begin(); it != sortIt.end(); ++it) {
    std::cout << *it << " ";
  }
  std::endl(std::cout);
  clock_t start = clock();
  mergeSort(sortIt);
  clock_t end = clock();
  std::cout << "After sorting:  ";
  for (std::vector<int>::iterator it = sortIt.begin(); it != sortIt.end(); ++it) {
    std::cout << *it << " ";
  }
  std::endl(std::cout);
  std::cout << "time: " << double(end - start) / CLOCKS_PER_MS << "ms" << std::endl;
  return (0);
}
