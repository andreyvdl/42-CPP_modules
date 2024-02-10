#ifndef MERGE_SORT_TPP
# define MERGE_SORT_TPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>

template <typename T>
void mergeSort(T& arr)
{
  if (arr.size() <= 2) {
    if (arr.size() == 2 && arr[0] > arr[1]) {
      std::swap(arr.at(0), arr.at(1));
    }
    return ;
  }

  typename T::iterator mid = arr.end() - arr.size() / 2;
  T l(arr.begin(), mid);
  T r(mid, arr.end());

  mergeSort(l);
  mergeSort(r);
  std::merge(l.begin(), l.end(), r.begin(), r.end(), arr.begin());
}





#endif
