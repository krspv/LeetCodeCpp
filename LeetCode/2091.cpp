#ifdef TASK_2091
#include <iostream>
#include <vector>
#include <memory>
#include <iterator>
#include <utility>
#include <algorithm>
using namespace std;


class Solution {
public:
  int minimumDeletions(vector<int>& nums) {
    int L = static_cast<int>(size(nums));
    if (L < 3) return L;

    int nMin(999'999), nMax(-999'999), nMinPos, nMaxPos;
    for (int i = 0; i < L; ++i) {
      if (nMin > nums[i]) {
        nMin = nums[i];
        nMinPos = i;
      }
      if (nMax < nums[i]) {
        nMax = nums[i];
        nMaxPos = i;
      }
    }

    if (nMinPos > nMaxPos) swap(nMinPos, nMaxPos);
    int L1 = nMinPos + 1, R1 = L - nMinPos, L2 = nMaxPos + 1, R2 = L - nMaxPos;

    return min({ L1 + R2, L2, R1 });
  }
};


int main() {
  cout << Solution().minimumDeletions(*make_unique<vector<int>>(vector{ 2, 10, 7, 5, 4, 1, 8, 6 })) << endl;
  cout << Solution().minimumDeletions(*make_unique<vector<int>>(vector{ 0, -4, 19, 1, 8, -2, -3, 5 })) << endl;
  cout << Solution().minimumDeletions(*make_unique<vector<int>>(vector{ 101 })) << endl;
}
#endif
