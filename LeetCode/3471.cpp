#ifdef TASK_3471
#include <iostream>
#include <vector>
#include <array>
#include <ranges>
using namespace std;


class Solution {
public:
  int largestInteger(vector<int>& nums, int k) {
    if (k > 1 && k < static_cast<int>(nums.size())) {
      if (nums.front() == nums.back()) return -1;
      for (int n : nums | views::drop(1) | views::take(nums.size() - 2)) {
        if (n == nums.front()) nums.front() = -1;
        if (n == nums.back()) nums.back() = -1;
        if (nums.front() == nums.back()) return -1;
      }
      return max(nums.front(), nums.back());
    }
    else {
      array<int, 51> counts{};
      for (int n : nums)
        ++counts[n];
      for (int idx = static_cast<int>(counts.size()) - 1; idx >= 0; --idx)
        if (counts[idx] == 1 || (k == static_cast<int>(nums.size()) && counts[idx] > 0))
          return idx;
      return -1;
    }
  }
};


int main() {
  cout << Solution().largestInteger(*make_unique<vector<int>>(vector{ 3, 9, 2, 1, 7 }), 3) << endl;
  cout << Solution().largestInteger(*make_unique<vector<int>>(vector{ 3, 9, 7, 2, 1, 7 }), 3) << endl;
  cout << Solution().largestInteger(*make_unique<vector<int>>(vector{ 0, 0 }), 1) << endl;
  cout << Solution().largestInteger(*make_unique<vector<int>>(vector{ 0, 0 }), 2) << endl;
  cout << Solution().largestInteger(*make_unique<vector<int>>(vector{ 5, 6, 6, 6, 8 }), 2) << endl;
  cout << Solution().largestInteger(*make_unique<vector<int>>(vector{ 5, 8, 6, 6, 8 }), 2) << endl;
  cout << Solution().largestInteger(*make_unique<vector<int>>(vector{ 3, 1, 7, 10, 0 }), 1) << endl;
  cout << Solution().largestInteger(*make_unique<vector<int>>(vector{ 3, 0, 12, 7, 1, 11 }), 6) << endl;
}
#endif
