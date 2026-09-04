#ifdef TASK_3903
#include <array>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;


class Solution {
public:
  int firstStableIndex(vector<int>& nums, int k) {
    array<int, 100> maxElems;
    const int L = static_cast<int>(size(nums));
    int tmp = -1, stable = -1;

    for (int i = 0; i < ssize(nums); ++i) {
      if (tmp < nums[i]) tmp = nums[i];
      maxElems[i] = tmp;
    }

    tmp = 1'000'000'001;
    for (int i = L - 1; i >= 0; --i) {
      if (tmp > nums[i]) tmp = nums[i];
      if (maxElems[i] - tmp <= k) stable = i;
    }

    return stable;
  }
};


int main() {
  cout << Solution().firstStableIndex(*make_unique<vector<int>>(vector{ 5, 0, 1, 4 }), 3) << endl;
  cout << Solution().firstStableIndex(*make_unique<vector<int>>(vector{ 3, 2, 1 }), 1) << endl;
  cout << Solution().firstStableIndex(*make_unique<vector<int>>(vector{ 0 }), 0) << endl;
}
#endif
