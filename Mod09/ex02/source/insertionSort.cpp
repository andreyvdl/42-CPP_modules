#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

template <typename T>
void insertionSort(T& arr)
{
  T temp;
  typename T::iterator it = arr.begin();

  temp.push_back(*it);
  while (++it != arr.end()) {
    for (typename T::iterator t = temp.begin(); t != temp.end(); ++t) {
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
