#include <deque>
#include <iostream>
#include <list>
#include <vector>

void insertionSort(std::deque<int>& arr);
void insertionSort(std::list<int>& arr);
void insertionSort(std::vector<int>& arr);
void mergeSort(std::deque<int>& arr);
void mergeSort(std::list<int>& arr);
void mergeSort(std::vector<int>& arr);

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
  mergeSort(sortIt);
  std::cout << "After sorting:  ";
  for (std::vector<int>::iterator it = sortIt.begin(); it != sortIt.end(); ++it) {
    std::cout << *it << " ";
  }
  std::endl(std::cout);
  return (0);
}
