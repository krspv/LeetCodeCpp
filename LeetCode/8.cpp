#ifdef TASK_8
#include <iostream>
#include <vector>
#include <array>
#include <limits>
using namespace std;


class Solution {
public:
  int myAtoi(const string &s) {
    int pos = 0;

    // Skip leading spaces
    while (pos < s.length() && s[pos] == ' ')
      ++pos;
    if (pos == s.length())
      return 0;

    // Determine the sign
    bool bNegative = false;
    if (s[pos] == '-') {
      bNegative = true;
      ++pos;
    }
    else if (s[pos] == '+')
      ++pos;

    // Skip leading zeros
    while (pos < s.length() && s[pos] == '0')
      ++pos;
    if (pos == s.length())
      return 0;

    // Extract the digits
    vector<int> digits;
    while (pos < s.length() && s[pos] >= '0' && s[pos] <= '9') {
      digits.push_back(static_cast<int>(s[pos++] - '0'));
      if (digits.size() > 10)
        break;
    }
    if (digits.empty())
      return 0;

    // Check for overflow
    if (digits.size() > 10)
      return bNegative ? numeric_limits<int>::min() : numeric_limits<int>::max();

    array<int, 10> maxInt{ 2, 1, 4, 7, 4, 8, 3, 6, 4, (bNegative ? 8 : 7) };
    if (digits.size() == 10) {
      for (int i = 0; i < 10; ++i) {
        if (maxInt[i] < digits[i]) return bNegative ? numeric_limits<int>::min() : numeric_limits<int>::max();
        else if (maxInt[i] > digits[i]) break;
      }
    }

    // Create the number
    int nOutput = 0;
    for (int digit : digits) {
      if (bNegative) digit = -digit;
      nOutput = 10 * nOutput + digit;
    }

    return nOutput;
  }
};


int main() {
  cout << Solution().myAtoi("10") << endl;
  cout << Solution().myAtoi("-25") << endl;
}
#endif
