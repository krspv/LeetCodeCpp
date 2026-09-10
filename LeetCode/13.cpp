#ifdef TASK_13
#include <iostream>
#include <string>
using namespace std;


class Solution {
private:
  inline int value(char ch) {
    switch (ch)
    {
    case 'M': return 1000;
    case 'D': return 500;
    case 'C': return 100;
    case 'L': return 50;
    case 'X': return 10;
    case 'V': return 5;
    case 'I': return 1;
    default: return -1234;
    }
  }

public:
  int romanToInt(const string& s) {
    int L = static_cast<int>(s.length());
    int ret = 0;
    int val = value(s[0]);
    for (int i = 0; i < L; ++i) {
      const int valNext = value(i == L - 1 ? '?' : s[i + 1]);
      ret += val < valNext ? -val : val;
      val = valNext;
    }
    return ret;
  }
};


int main() {
  cout << Solution().romanToInt("III") << endl;
  cout << Solution().romanToInt("LVIII") << endl;
  cout << Solution().romanToInt("MCMXCIV") << endl;
}
#endif
