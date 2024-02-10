#ifndef INSERTION_SORT_TPP
# define INSERTION_SORT_TPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>

template <typename T>
void insertionSort(T& arr)
{
  T sort;
  typename T::iterator it = arr.begin();

  sort.push_back(*it);
  while (++it != arr.end()) {
    typename T::iterator t = std::lower_bound(sort.begin(), sort.end(), *it);

    if (t != sort.end()) {
      sort.insert(t, *it);
    } else {
      sort.push_back(*it);
    }
  }
  arr = sort;
}

#endif
