#ifdef TASK_2948
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <ranges>
#include <utility>
#include <iterator>
using namespace std;


class Solution {
public:
  vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    vector<pair<int, int>> valPos;
    valPos.reserve(nums.size());
    int pos = 0;
    for (int num : nums)
      valPos.emplace_back(num, pos++);
    sort(begin(valPos), end(valPos), [](const pair<int, int>& lhs, const pair<int, int>& rhs) { return lhs.first < rhs.first; });

    vector<int> out(nums.size());
    vector<int> indices;
    indices.reserve(nums.size());

    auto itStart = begin(valPos);
    while (itStart != valPos.end()) {
      indices.clear();
      indices.push_back(itStart->second);
      auto itEnd = next(itStart);
      while (itEnd != valPos.end() && itEnd->first - prev(itEnd)->first <= limit) {
        indices.push_back(itEnd->second);
        ++itEnd;
      }
      sort(begin(indices), end(indices));
      pos = 0;
      for (const auto &pr : ranges::subrange(itStart, itEnd))
        out[indices[pos++]] = pr.first;
      itStart = itEnd;
    }

    return out;
  }
};


static void printVec(const vector<int>& vec) {
  for (int num : vec) {
    cout << num << ' ';
  }
  cout << endl;
}


int main() {
  printVec(Solution().lexicographicallySmallestArray(*make_unique<vector<int>>(vector{ 1, 5, 3, 9, 8 }), 2));
  printVec(Solution().lexicographicallySmallestArray(*make_unique<vector<int>>(vector{ 1, 7, 6, 18, 2, 1 }), 3));
  printVec(Solution().lexicographicallySmallestArray(*make_unique<vector<int>>(vector{ 1, 7, 28, 19, 10 }), 3));
  printVec(Solution().lexicographicallySmallestArray(*make_unique<vector<int>>(vector{ 1, 60, 34, 84, 62, 56, 39, 76, 49, 38 }), 4));
  printVec(Solution().lexicographicallySmallestArray(*make_unique<vector<int>>(vector{ 5, 100, 44, 45, 16, 30, 14, 65, 83, 64 }), 15));
}
#endif
