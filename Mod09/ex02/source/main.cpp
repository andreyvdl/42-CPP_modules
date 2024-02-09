#include <iostream>
#include <deque>
#include <vector>
#include <list>

void insertionSort(std::deque<int>& arr);
void insertionSort(std::list<int>& arr);
void insertionSort(std::vector<int>& arr);

/*
 * TODO:
 * Implement insertion sort X
 * Test insertion sort implementation with deque X
 * Test insertion sort implementation with list X
 * Test insertion sort implementation with vector X
 * Implement merge sort
 * Test merge sort implementation with deque
 * Test merge sort implementation with list
 * Test merge sort implementation with vector
 * Implement Ford-Jonhson of wikipedia
 * Test wikipedia Ford-Jonhson
 * Implement Ford-Johnson of stackExchange
 * Test stackExchange Ford-Johnson
 * Implement Ford-Johnson of G2G
 * Test G2G Ford-Johnson
 * Implement Ford-Johnson of IQ
 * Test IQ Ford-Johnson
 */

int main(void)
{
  std::list<int> sortIt;

  sortIt.push_back(5);
  sortIt.push_back(-4);
  sortIt.push_back(3);
  sortIt.push_back(-2);
  sortIt.push_back(1);
  sortIt.push_back(0);
  for (std::list<int>::iterator it = sortIt.begin(); it != sortIt.end(); ++it) {
    std::cout << *it << " ";
  }
  std::endl(std::cout);
  insertionSort(sortIt);
  for (std::list<int>::iterator it = sortIt.begin(); it != sortIt.end(); ++it) {
    std::cout << *it << " ";
  }
  std::endl(std::cout);
  return (0);
}
