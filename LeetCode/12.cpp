#ifdef TASK_12
#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
  string intToRoman(int num) {
    string ret;
    int ordinal = 0;
    while (num) {
      int digit = num % 10;
      num /= 10;
      switch (ordinal) {
      case 0:
        switch (digit) {
        case 1: ret = "I"; break;
        case 2: ret = "II"; break;
        case 3: ret = "III"; break;
        case 4: ret = "IV"; break;
        case 5: ret = "V"; break;
        case 6: ret = "VI"; break;
        case 7: ret = "VII"; break;
        case 8: ret = "VIII"; break;
        case 9: ret = "IX"; break;
        }
        break;
      case 1:
        switch (digit) {
        case 1: ret = "X" + ret; break;
        case 2: ret = "XX" + ret; break;
        case 3: ret = "XXX" + ret; break;
        case 4: ret = "XL" + ret; break;
        case 5: ret = "L" + ret; break;
        case 6: ret = "LX" + ret; break;
        case 7: ret = "LXX" + ret; break;
        case 8: ret = "LXXX" + ret; break;
        case 9: ret = "XC" + ret; break;
        }
        break;
      case 2:
        switch (digit) {
        case 1: ret = "C" + ret; break;
        case 2: ret = "CC" + ret; break;
        case 3: ret = "CCC" + ret; break;
        case 4: ret = "CD" + ret; break;
        case 5: ret = "D" + ret; break;
        case 6: ret = "DC" + ret; break;
        case 7: ret = "DCC" + ret; break;
        case 8: ret = "DCCC" + ret; break;
        case 9: ret = "CM" + ret; break;
        }
        break;
      case 3:
        switch (digit) {
        case 1: ret = "M" + ret; break;
        case 2: ret = "MM" + ret; break;
        case 3: ret = "MMM" + ret; break;
        }
        break;
      }
      ++ordinal;
    }
    return ret;
  }
};


int main() {
  cout << Solution().intToRoman(3749) << endl;
  cout << Solution().intToRoman(58) << endl;
}
#endif
