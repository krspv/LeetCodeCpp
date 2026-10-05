#ifdef TASK_32
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <utility>
using namespace std;


class Solution {
public:
  int longestValidParentheses(const string& s) {
    if (s.empty()) return 0;

    list<pair<int, int>> sequences;

    int pos = static_cast<int>(s.find("()"));
    while (pos != string::npos) {
      if (sequences.empty() || sequences.back().second != pos - 1)
        sequences.emplace_back(pos, pos + 1);
      else
        sequences.back().second = pos + 1;
      pos = static_cast<int>(s.find("()", pos + 2));
    }

    if (sequences.empty()) return 0;

    bool bExpandOrJoin;
    int L = static_cast<int>(s.length());
    do {
      bExpandOrJoin = false;

      for (auto& [first, last] : sequences) {
        int f1 = first - 1, l1 = last + 1;
        while (f1 >= 0 && l1 < L) {
          if (s[f1] == '(' && s[l1] == ')') {
            bExpandOrJoin = true;
            --first, ++last, --f1, ++l1;
          }
          else
            break;
        }
      }

      if (bExpandOrJoin) {
        auto it = begin(sequences);
        while (it != end(sequences)) {
          auto nxt = next(it);
          if (nxt != end(sequences) && it->second + 1 == nxt->first) {
            it->second = nxt->second;
            sequences.erase(nxt);
            bExpandOrJoin = true;
          }
          else
            ++it;
        }
      }

    } while (bExpandOrJoin);

    auto itMax = ranges::max_element(sequences, {}, [](const pair<int, int>& seq) {return seq.second - seq.first; });
    return itMax->second - itMax->first + 1;
  }
};


int main() {
  cout << Solution().longestValidParentheses("(()") << endl;
  cout << Solution().longestValidParentheses(")()())") << endl;
  cout << Solution().longestValidParentheses("") << endl;
  cout << Solution().longestValidParentheses(")))(((") << endl;
  cout << Solution().longestValidParentheses(")(()))))))()(()))") << endl;
  cout << Solution().longestValidParentheses("()(()") << endl;
}
#endif
