#include <deque>
#include <iostream>
#include <list>
#include <vector>

void mergeSort(std::deque<int>& arr)
{
  if (arr.size() == 1) {
    return ;
  }

  std::deque<int>::iterator mid = arr.end() - arr.size() / 2;
  std::deque<int> left(arr.begin(), mid);
  std::deque<int> right(mid, arr.end());

  mergeSort(left);
  mergeSort(right);

  std::deque<int> temp;
  std::deque<int>::iterator l = left.begin();
  std::deque<int>::iterator r = right.begin();

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

void mergeSort(std::list<int>& arr)
{
  if (arr.size() == 1) {
    return ;
  }

  int size = arr.size() / 2;
  std::list<int>::iterator mid = arr.end();

// iterator de list e ruim, nao use
  while (size--) {
    --mid;
  }
  std::list<int> left(arr.begin(), mid);
  std::list<int> right(mid, arr.end());

  mergeSort(left);
  mergeSort(right);

  std::list<int> temp;
  std::list<int>::iterator l = left.begin();
  std::list<int>::iterator r = right.begin();

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

void mergeSort(std::vector<int>& arr)
{
  if (arr.size() == 1) {
    return ;
  }

  std::vector<int>::iterator mid = arr.end() - arr.size() / 2;
  std::vector<int> left(arr.begin(), mid);
  std::vector<int> right(mid, arr.end());

  mergeSort(left);
  mergeSort(right);

  std::vector<int> temp;
  std::vector<int>::iterator l = left.begin();
  std::vector<int>::iterator r = right.begin();

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
