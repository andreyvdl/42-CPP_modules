#include <deque>
#include <iostream>
#include <vector>

template <typename T>
void mergeSort(T& arr)
{
  if (arr.size() == 1) {
    return ;
  }

  typename T::iterator mid = arr.end() - arr.size() / 2;
  T left(arr.begin(), mid);
  T right(mid, arr.end());

  mergeSort(left);
  mergeSort(right);

  T temp;
  typename T::iterator l = left.begin();
  typename T::iterator r = right.begin();

  do {
    if (*l < *r) {
      temp.push_back(*l);
      ++l;
    } else {
      temp.push_back(*r);
      ++r;
    }
  } while (l != left.end() && r != right.end());
  l == left.end() ? temp.insert(temp.end(), r, right.end()) :
    temp.insert(temp.end(), l, left.end());
  arr = temp;
}
