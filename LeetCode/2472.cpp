#ifdef TASK_2472
#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
  int maxPalindromes(const string &s, int k) {
    if (k == 1)
      return static_cast<int>(s.length());
    if (k > s.length())
      return 0;

    const int L = static_cast<int>(s.length());
    int nCount = 0;
    for (int i = 0; i < L - k + 1; ++i) {
      int t = i;
      int j = i + k - 1;
      while (t < j && s[t] == s[j]) {
        t++;
        j--;
      }
      if (t >= j) {
        ++nCount;
        i = i + k - 1;
      }
      else if (i + k < L) {
        t = i;
        j = i + k;
        while (t < j && s[t] == s[j]) {
          t++;
          j--;
        }
        if (t >= j) {
          ++nCount;
          i = i + k;
        }
      }
    }

    return nCount;
  }
};


int main() {
  cout << Solution().maxPalindromes("kxoxkbalabrefer", 2) << endl;
  cout << Solution().maxPalindromes("xccrbbrccayzz", 2) << endl;
  cout << Solution().maxPalindromes("aaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa", 3) << endl;
  cout << Solution().maxPalindromes("abaccdbbd", 3) << endl;
  cout << Solution().maxPalindromes("adbcda", 2) << endl;
  cout << Solution().maxPalindromes("sjbxiufnaanqkwsqswkqrcznzcddhtuhtthuttjfuufjtcfywgecegwyhhnnhtozczirynhhnyrire", 3) << endl;
  cout << Solution().maxPalindromes("fttfjofpnpfydwdwdnns", 2) << endl;
  cout << Solution().maxPalindromes("zqzogfurlfmrnlffuipuupidkfhkggkhdrzezghwziopoinnsdkwkymhygonbiizmmmmzjhmyczzlz", 2) << endl;
}
#endif
