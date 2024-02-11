#include <deque>
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <limits>

#include "mergeSort.template.tpp"
#include "insertionSort.template.tpp"
#include "../include/PmergeMe.class.hpp"

#define CLOCKS_PER_MS 1000

template <typename T>
std::string getNumbers(T& arr);

bool isSorted(std::vector<int>& arr);
void letsSort(std::vector<int>& hold);
void removeWhitespaces(std::string& str);

int main(int argc, char** argv)
{
  if (argc == 1) {
    std::cout << "Error: no arguments" << std::endl;
    return (-1);
  }

  std::vector<int> hold;

  for (int i = 1; i < argc; ++i) {
    std::string arg(argv[i]);

    removeWhitespaces(arg);
    if (arg.find_first_not_of("0123456789") != std::string::npos) {
      std::cout << "Error: only positive numbers" << std::endl;
      return (-2);
    }

    std::istringstream iss(arg);
    ssize_t nbr;

    iss.exceptions(std::ios::failbit);
    iss >> nbr;
    if (0 > nbr || nbr > std::numeric_limits<int>::max()) {
      std::cout << "Error: over/under flows the limit" << std::endl;
      return (-3);
    }
    hold.push_back(static_cast<int>(nbr));
  }
  if (hold.size() == 1 || isSorted(hold)) {
    std::cout << "Error: array already sorted" << std::endl;
    return (-4);
  }
  letsSort(hold);
  return (0);
}

void letsSort(std::vector<int>& hold)
{
  clock_t start, end;
  std::deque<int> h2(hold.begin(), hold.end()), sorted1(h2);
  std::vector<int> sorted2(hold);
  PmergeMe ford;

  std::cout << "Unsorted Vector: " << getNumbers(hold) << std::endl;
  start = clock();
  ford.fordJohnVec(sorted2);
  end = clock();
  std::cout << "Sorted Vector: " << getNumbers(sorted2) << std::endl;
  if (isSorted(sorted2) == false) {
    std::cout << "OH NO SOMETHING WENT VERY WRONG!" << std::endl;
    return ;
  }
  std::cout << "Time to sort vector with ford ~= "
    << static_cast<double>(end - start) / CLOCKS_PER_MS << "ms" << std::endl;
  start = clock();
  ford.fordJohnDeq(sorted1);
  end = clock();
  std::cout << "Time to sort deque with ford ~= "
    << static_cast<double>(end - start) / CLOCKS_PER_MS << "ms" << std::endl;

  std::endl(std::cout);
  std::cout << "================================================" << std::endl;
  std::endl(std::cout);

  std::deque<int> sorted3(h2), sorted4(h2), sorted5(h2);
  std::vector<int> sorted6(hold), sorted7(hold), sorted8(hold);

  start = clock();
  mergeSort(sorted6);
  end = clock();
  if (isSorted(sorted6) == false) {
    std::cout << "OH NO SOMETHING WENT VERY WRONG!" << std::endl;
    return ;
  }
  std::cout << "Time to sort vector with merge ~= "
    << static_cast<double>(end - start) / CLOCKS_PER_MS << "ms" << std::endl;
  start = clock();
  mergeSort(sorted3);
  end = clock();
  std::cout << "Time to sort deque with merge ~= "
    << static_cast<double>(end - start) / CLOCKS_PER_MS << "ms" << std::endl;

  std::endl(std::cout);

  start = clock();
  insertionSort(sorted7);
  end = clock();
  if (isSorted(sorted7) == false) {
    std::cout << "OH NO SOMETHING WENT VERY WRONG!" << std::endl;
    return ;
  }
  std::cout << "Time to sort vector with insertion ~= "
    << static_cast<double>(end - start) / CLOCKS_PER_MS << "ms" << std::endl;
  start = clock();
  insertionSort(sorted4);
  end = clock();
  std::cout << "Time to sort deque with insertion ~= "
    << static_cast<double>(end - start) / CLOCKS_PER_MS << "ms" << std::endl;

  std::endl(std::cout);

  start = clock();
  std::sort(sorted8.begin(), sorted8.end());
  end = clock();
  if (isSorted(sorted8) == false) {
    std::cout << "OH NO SOMETHING WENT VERY WRONG!" << std::endl;
    return ;
  }
  std::cout << "Time to sort vector with std::sort ~= "
    << static_cast<double>(end - start) / CLOCKS_PER_MS << "ms" << std::endl;
  start = clock();
  std::sort(sorted5.begin(), sorted5.end());
  end = clock();
  std::cout << "Time to sort deque with std::sort ~= "
    << static_cast<double>(end - start) / CLOCKS_PER_MS << "ms" << std::endl;
}

template <typename T>
std::string getNumbers(T& arr)
{
  std::stringstream ss;

  for (typename T::iterator it = arr.begin(); it != arr.end(); ++it) {
    ss << *it << " ";
  }
  return (ss.str());
}
