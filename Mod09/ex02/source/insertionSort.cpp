#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

void insertionSort(std::deque<int>& arr)
{
  std::deque<int> temp;
  std::deque<int>::iterator it = arr.begin();

  temp.push_back(*it);
  while (++it != arr.end()) {
    for (std::deque<int>::iterator t = temp.begin(); t != temp.end(); ++t) {
      if (*it < *t) {
        temp.insert(t, *it);
        break;
      }
      if (t + 1 == temp.end()) {
        temp.push_back(*it);
      }
    }
  }
  arr = temp;
}

void insertionSort(std::vector<int>& arr)
{
  std::vector<int> temp;
  std::vector<int>::iterator it = arr.begin();

  temp.push_back(*it);
  while (++it != arr.end()) {
    for (std::vector<int>::iterator t = temp.begin(); t != temp.end(); ++t) {
      if (*it < *t) {
        temp.insert(t, *it);
        break;
      }
      if (t + 1 == temp.end()) {
        temp.push_back(*it);
      }
    }
  }
  arr = temp;
}

void insertionSort(std::list<int>& arr)
{
  std::list<int> temp;
  std::list<int>::iterator it = arr.begin();
  bool inserted = false;

  temp.push_back(*it);
  while (++it != arr.end()) {
    for (std::list<int>::iterator t = temp.begin(); t != temp.end(); ++t) {
      if (*it < *t) {
        temp.insert(t, *it);
        inserted = true;
        break;
      }
    }
// precisa pq o iterator de list nao permite somar um valor
    if (inserted == false) {
      temp.push_back(*it);
    }
    inserted = false;
  }
  arr = temp;
}

