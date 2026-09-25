#ifdef TASK_3524
#include <algorithm>
#include <ios>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;


#define UKU \
    printVec(Solution().peski(nums, k)); \
    printVec(Solution().resultArray(nums, k)); \
    cout << endl
#define UKUC \
    { \
      auto v1 = Solution().peski(nums, k); \
      auto v2 = Solution().resultArray(nums, k); \
      cout << boolalpha << equal(begin(v1), end(v1), begin(v2)) << endl; \
    }


class Solution {
public:
  vector<long long> peski(vector<int>& nums, int k) {
    vector<long long> ret(k);

    int L = static_cast<int>(size(nums));
    for (int i = 0; i < L; ++i) {
      long long div = nums[i] % k;
      ++ret[div];
      for (int j = i - 1; j >= 0; --j) {
        div = (div * nums[j]) % k;
        ++ret[div];
      }
    }

    return ret;
  }

  vector<long long> resultArray(vector<int>& nums, int k) {
    vector<long long> ret(k);

    int L = static_cast<int>(size(nums));
    vector<int> dp(L * k, 0); // Element (i,j) is dp[i*k + j]
    for (int i = 0; i < L; ++i) {
      int div = nums[i] % k;
      if (div > 0) {
        ++dp[i * k + div];
        if (i > 0) {
          for (int r = 0; r < k; ++r) {
            if (dp[(i - 1) * k + r] > 0) {
              int prod = (r * div) % k;
              dp[i * k + prod] += dp[(i - 1) * k + r];
            }
          }
        }
      }
      else dp[i * k] = i + 1;

      for (int r = 0; r < k; ++r)
        ret[r] += dp[i * k + r];
    }

    return ret;
  }
};


template <typename T>
static void printVec(const vector<T>& vec) {
  for (const T &item : vec)
    cout << item << ' ';
  cout << endl;
}


int main() {
  vector<int> nums;
  int k;

  nums = { 1, 2, 3, 4, 5 }, k = 3;        UKU;
  nums = { 1, 2, 4, 8, 16, 32 }, k = 4;   UKU;
  nums = { 1, 1, 2, 1, 1 }, k = 2;        UKU;
  nums = { 2, 2 }, k = 5;                 UKU;
  nums = { 10, 2 }, k = 4;                UKU;
  nums = { 5, 2, 8, 9 }, k = 3;           UKU;
  nums = { 7, 9 }, k = 4;                 UKU;
  nums = { 2, 2, 2, 2, 2 }, k = 4;        UKU;
  nums = { 1, 2, 8, 6, 7, 3 }, k = 5;     UKU;
  nums = { 3, 2, 2, 2 }, k = 4;           UKU;
}
#endif
