#ifndef FORD_JOHNSON_TEMPLATE_TPP
# define FORD_JOHNSON_TEMPLATE_TPP

# include <algorithm>
# include <deque>
# include <iostream>
# include <utility>
# include <vector>

/*
 * https://www.wikiwand.com/en/Merge-insertion_sort
 *
 * 1. Group the elements of INPUT into FLOOR(N/2) pairs of elements,
 *    arbitrarily, leaving one element unpaired if there is an odd number of
 *    elements.
 * 2. Perform FLOOR(N/2) comparisons, one per pair, to determine the larger of
 *    the two elements in each pair.
 * 3. Recursively sort the FLOOR(N/2) larger elements from each pair, creating
 *    a sorted sequence S of FLOOR(N/2) of the input elements, in ascending
 *    order.
 * 4. Insert at the start of S the element that was paired with the first and
 *    smallest element of S.
 * 5. Insert the remaining CEIL(N/2)-1 elements of INPUT\S into S, one at a
 *    time, with a specially chosen insertion ordering described below. Use
 *    binary search in subsequences of S (as described below) to determine the
 *    position at which each element should be inserted.
 *
 * Reference 6 of the wikipedia text just below the Algorithm header:
 * "The original description by Ford & Johnson (1959) sorted the elements in
 *  descending order. The steps listed here reverse the output, following the
 *  description in Knuth (1998). The resulting algorithm makes the same
 *  comparisons but produces ascending order instead."
 */

/*
 * STEP 1
 */
template <typename T, typename U>
void  createPairs(T& k, U arr, std::pair<bool, int>& e, bool const odd)
{
  typename U::iterator ait = arr.begin();
  typename U::iterator end = arr.end() - (odd ? 1 : 0);

  do {
    k.push_back(std::make_pair(*ait++, *ait++));
  } while (ait != end);
// e = unpaired element
  e = (odd ? std::make_pair(odd, *ait) : std::make_pair(odd, 0));
}

void  sortKGroups(std::pair<int, int>& pair)
{
// the first element of the pair must be the biggest
  if (pair.first < pair.second) {
    std::swap(pair.first, pair.second);
  }
}

/*
 * STEP 2
 */
template <typename T>
void  determineLargerElement(T& k)
{
  std::for_each(k.begin(), k.end(), sortKGroups);
}

bool  higherPos(const int& v, const int& itContent)
{
  return (v < itContent);
}

/*
 * STEP 3
 * A more simple way to do this is to add all s.first and e.second elements
 * and then calling std::sort.
 */
template <typename T, typename U>
void  sortOnlyBiggers(typename T::iterator kis, typename T::iterator kie,
  U& s, std::pair<bool, int> e
)
{
  if (kis != kie) {
    sortOnlyBiggers<T, U>(kis + 1, kie, s, e);
  } else if (e.first) {
    s.push_back(e.second);
    return ;
  } else {
    return ;
  }

  s.insert(std::upper_bound(s.begin(), s.end(), kis->first, higherPos),
    kis->first
  );
}

bool  lowerPos(std::pair<int, int>& pair, const int& v)
{
  return (pair.first < v);
}

/*
 * STEP 4
 */
template <typename T, typename U>
void  insertLowest(T& k, U& s)
{
  typename T::iterator lowest = std::lower_bound(k.begin(), k.end(), s[0],
    lowerPos
  );

  if (lowest != k.end()) {
    s.insert(s.begin(), lowest->second);
    k.erase(lowest);
  }
}

/*
 * STEP 5
 */
template <typename T, typename U>
void  binaryInsertion(T& k, U& s)
{
  for (typename T::iterator kit = k.begin(); kit != k.end(); ++kit) {
    typename U::iterator hit = s.end();
    typename U::iterator lit = s.begin();

    while (lit < hit) {
      ssize_t dist = (hit - lit) / 2;

      if (dist == 0) {
        break ;
      }
      if (*(lit + dist) < kit->second) {
        lit += dist + 1;
      } else if (*(hit - dist) > kit->second) {
        hit -= dist;
      } else if (*(hit - dist) == kit->second) {
        lit = hit - dist;
        break;
      } else if (*(lit + dist) == kit->second) {
        lit += dist;
        break;
      }
    }
    *lit >= kit->second ?
      s.insert(lit, kit->second) :
      s.insert(hit, kit->second);
  }
}



#endif
