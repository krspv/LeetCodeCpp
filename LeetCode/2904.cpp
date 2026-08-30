#ifdef TASK_2904
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
  string shortestBeautifulSubstring(const string& s, int k) {
    vector<int> sums;
    sums.reserve(s.length() + 1);
    sums.push_back(0);
    int total = 0;
    for (char ch : s) {
      if (ch == '1') ++total;
      sums.push_back(total);
    }

    int l = -1, r = static_cast<int>(s.length());
    const int L1 = r, L = r + 1;
    string ret;
    for (int i = 0; i < L1; ++i) {
      for (int j = i + 1; j < L; ++j)
        if (sums[j] - sums[i] == k) {
          if (j - i < r - l) {
            l = i;
            r = j;
            ret = s.substr(l, r-l);
            break;
          }
          else if (j - i == r - l) {
            string sub = s.substr(i, j-i);
            if (sub < ret) {
              ret = sub;
              l = i;
              r = j;
              break;
            }
          }
        }
      if (r - l == k)
        break;
    }

    return ret;
  }
};


int main() {
  cout << Solution().shortestBeautifulSubstring("100011001", 3) << endl;
  cout << Solution().shortestBeautifulSubstring("1011", 2) << endl;
  cout << Solution().shortestBeautifulSubstring("000", 1) << endl;
  cout << Solution().shortestBeautifulSubstring("1100001110111100100", 8) << endl;
}
#endif
