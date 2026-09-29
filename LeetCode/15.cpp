#ifdef TASK_15
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;


class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> vecRet;

    int L = static_cast<int>(size(nums));
    sort(begin(nums), end(nums));

    int first = -100'001;
    auto i = begin(nums);
    while (true) {
      if (*i > first)
        first = *i;
      else {
        if (next(i) != end(nums) && *next(i) > *i)
          first = *++i;
        else {
          i = upper_bound(i, end(nums), first);
          if (i == end(nums))
            break;
          else
            first = *i;
        }
      }

      if (first > 0) break;
      if (distance(i, end(nums)) < 3) break;

      int second = first - 1;
      auto j = next(i);
      while (true) {
        if (*j > second)
          second = *j;
        else {
          if (next(j) != end(nums) && *next(j) > second)
            second = *++j;
          else {
            j = upper_bound(j, end(nums), second);
            if (j == end(nums))
              break;
            else
              second = *j;
          }
        }
        if (distance(j, end(nums)) < 2) break;
        if (first + second + nums.back() < 0) continue;

        int third = -(first + second);
        if (binary_search(next(j), end(nums), third))
          vecRet.push_back({ first, second, third });
      }
    }

            
    return vecRet;
  }

  vector<vector<int>> threeSumAI(vector<int>& nums) { // This one is faster
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = static_cast<int>(size(nums));

    for (int i = 0; i < n - 2; ++i) {
      if (nums[i] > 0) break;                        // smallest is positive -> no triplet
      if (i > 0 && nums[i] == nums[i - 1]) continue;  // skip duplicate 'first'

      int lo = i + 1, hi = n - 1;
      while (lo < hi) {
        int sum = nums[i] + nums[lo] + nums[hi];
        if (sum < 0) {
          ++lo;
        }
        else if (sum > 0) {
          --hi;
        }
        else {
          result.push_back({ nums[i], nums[lo], nums[hi] });
          ++lo; --hi;
          while (lo < hi && nums[lo] == nums[lo - 1]) ++lo; // skip dup 'second'
          while (lo < hi && nums[hi] == nums[hi + 1]) --hi; // skip dup 'third'
        }
      }
    }
    return result;
  }
};


static void printVec(const vector<vector<int>>& vec) {
  static int example = 0;
  cout << "Example " << ++example << ":\n";
  for (const auto& lineVec : vec) {
    for (int item:lineVec)
      cout << item << ' ';
    cout << endl;
  }
  cout << endl;
}


int main() {
  vector<int> nums;

  printVec(Solution().threeSum(nums = { -1, 0, 1, 2, -1, -4 }));
  printVec(Solution().threeSum(nums = { 0, 1, 1 }));
  printVec(Solution().threeSum(nums = { 0, 0, 0 }));
  printVec(Solution().threeSum(nums = { 1, 1, -2 }));
}
#endif
