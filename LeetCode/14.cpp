#ifdef TASK_14  
#include <algorithm>
#include <iostream>
#include <memory>
#include <ranges>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0) return "";
    if (strs.size() == 1) return strs[0];

    size_t k = 0;
    const string& str1 = strs[0];
    while (k < str1.length() && k < strs[1].length() && str1[k] == strs[1][k]) ++k;

    for (const string& str : strs | views::drop(2)) {
      size_t l = 0;
      while (l < str1.length() && l < str.length() && l < k && str1[l] == str[l]) ++l;
      k = min(k, l);
      if (k == 0) break;
    }

    return k == 0 ? "" : strs[0].substr(0, k);
  }
};


int main() {
  cout << Solution().longestCommonPrefix(*make_unique<vector<string>>(vector<string>{"flower", "flow", "flight"})) << endl;
  cout << Solution().longestCommonPrefix(*make_unique<vector<string>>(vector<string>{"froolic", "froolic", "fraodf", "frloadsf", "frlozcv"})) << endl;
  cout << Solution().longestCommonPrefix(*make_unique<vector<string>>(vector<string>{"baab", "bacb", "b", "cbc"})) << endl;
}
#endif
