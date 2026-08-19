#ifdef TASK_7
#include <iostream>
#include <vector>
#include <array>
#include <numeric>
using namespace std;


class Solution {
public:
  int reverse(int x) {
    array<int, 10> maxNeg{ -2, -1, -4, -7, -4, -8, -3, -6, -4, -8 };
    array<int, 10> maxPos{ 2, 1, 4, 7, 4, 8, 3, 6, 4, 7 };
    bool bPositive = x >= 0;
    vector<int> digits;
    while (x != 0) {
      digits.push_back(x % 10);
      x /= 10;
    }
    if (digits.size() == 10) {
      for (int i = 0; i < 10; ++i) {
        if ((bPositive && maxPos[i] < digits[i]) || (!bPositive && maxNeg[i] > digits[i])) return 0;
        else if ((bPositive && maxPos[i] > digits[i]) || (!bPositive && maxNeg[i] < digits[i])) break;
      }
    }
    return accumulate(begin(digits), end(digits), 0, [](int acc, int cur) { return 10 * acc + cur; });
  }
};


int main() {
  cout << Solution().reverse(-1) << endl;
  cout << Solution().reverse(1) << endl;
  cout << Solution().reverse(-12345) << endl;
  cout << Solution().reverse(12345) << endl;
  cout << Solution().reverse(-1'111'157'412) << endl;
  cout << Solution().reverse(1'111'157'412) << endl;
  cout << Solution().reverse(-1'999'937'412) << endl;
  cout << Solution().reverse(1'999'937'412) << endl;
}
#endif
