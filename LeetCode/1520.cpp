#ifdef TASK_1520
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>
using namespace std;


class Solution {
public:
  vector<string> maxNumOfSubstrings(const string& s) {
    vector<int> froms(26, -1), tos(26, -1), used;

    for (size_t i = 0; i < s.length(); ++i) {
      int nChPos = s[i] - 'a';
      if (froms[nChPos] == -1) {
        froms[nChPos] = static_cast<int>(i);
        used.push_back(nChPos);
      }
      tos[nChPos] = static_cast<int>(i);
    }

    // Expand ranges
    for (size_t i = 0; i < s.length(); ++i) {
      int nChPos = s[i] - 'a';
      for (int idx : used)
        if (idx != nChPos && froms[idx] <= i && i <= tos[idx]) {
          froms[idx] = min(froms[idx], froms[nChPos]);
          tos[idx] = max(tos[idx], tos[nChPos]);
        }
    }

    // Construct unique ranges [unique means no duplicates]
    vector<pair<int, int>> rngz;
    for (int i : used) {
      bool bExists = false;
      for (auto& [fx, tx] : rngz) {
        if (fx == froms[i] && tx == tos[i]) {
          bExists = true;
          break;
        }
      }
      if (!bExists)
        rngz.push_back(make_pair(froms[i], tos[i]));
    }

    // Remove ranges that encompass other ranges
    vector<pair<int, int>> rngz2;
    for (size_t i = 0; i < size(rngz); ++i) {
      bool bRemove = false;
      for (size_t j = 0; j < size(rngz); ++j)
        if (i != j && rngz[j].first != -1 && rngz[i].first <= rngz[j].first && rngz[j].second <= rngz[i].second) {
          bRemove = true;
          break;
        }
      if (!bRemove) rngz2.push_back(rngz[i]);
    }

    sort(begin(rngz2), end(rngz2), [](const auto& lhs, const auto& rhs) { return lhs.second < rhs.second; });

    vector<string> ret;
    int lastEnd = -1;
    for (auto& [from, to] : rngz2) {
      if (from > lastEnd) {
        ret.push_back(s.substr(from, to - from + 1));
        lastEnd = to;
      }
    }

    return ret;
  }
};


static void printVec(const vector<string>& vec) {
  for (string s : vec)
    cout << s << ' ';
  cout << endl;
}


int main() {
  printVec( Solution().maxNumOfSubstrings("adefaddaccc") );
  printVec( Solution().maxNumOfSubstrings("abbaccd") );
  printVec( Solution().maxNumOfSubstrings("abab") );
  printVec( Solution().maxNumOfSubstrings("ababa") );
}
#endif
