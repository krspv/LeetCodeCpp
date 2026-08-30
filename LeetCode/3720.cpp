#ifdef TASK_3720
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <utility>
using namespace std;


class Solution {
public:
  string lexGreaterPermutation(const string &s, const string &target) {
    int count[26] = { 0 };
    for (char c : s) ++count[c - 'a'];
    const int L = static_cast<int>(s.length());
    
    // Check if a greater string is possible
    string out(L, ' ');
    for (int i = 25, idx = 0; i >= 0; --i)
      for (int j = 0; j < count[i]; ++j)
        out[idx++] = 'a' + i;
    sort(begin(out), end(out), greater<char>());
    if (out <= target) return "";

    // Match
    int iTgt = 0, iOut = 0;
    while (iTgt < L) {
      char ch = target[iTgt];
      if (count[ch - 'a'] > 0) {
        --count[ch - 'a'];
        out[iOut++] = ch;
        ++iTgt;
      }
      else
        break;
    }

    int iLastEq = iOut - 1;
    // Add the rest
    for (int i = 0; i < 26 && iOut < L; ++i)
      while (count[i] > 0) {
        --count[i];
        out[iOut++] = 'a' + i;
      }

    if (out <= target) {
      if (iLastEq + 1 < L) ++iLastEq;
      for (; iLastEq >= 0; --iLastEq) {
        char ch = 'a' + 30;
        int pos = -1;
        char chTgt = target[iLastEq];
        for (int i = iLastEq + 1; i < L; ++i) {
          if (out[i] > chTgt && ch > out[i]) {
            ch = out[i];
            pos = i;
          }
        }
        if (pos != -1) {
          swap(out[pos], out[iLastEq]);
          sort(begin(out) + iLastEq + 1, end(out));
          break;
        }
      }
    }
    return out;
  }
};


int main() {
  cout << Solution().lexGreaterPermutation("abc", "bba") << endl;
  cout << Solution().lexGreaterPermutation("leet", "code") << endl;
  cout << Solution().lexGreaterPermutation("baba", "bbaa") << endl;
  cout << Solution().lexGreaterPermutation("ab", "ab") << endl;
  cout << Solution().lexGreaterPermutation("bb", "ba") << endl;
  cout << Solution().lexGreaterPermutation("aab", "aba") << endl;
  cout << Solution().lexGreaterPermutation("aab", "abb") << endl;
  cout << Solution().lexGreaterPermutation("aabb", "abba") << endl;
  cout << Solution().lexGreaterPermutation("abcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeabcde", "edcbaedcbaedcbaedcbaedcbaedcbaedcbaedcbaedcbaedcba") << endl;
  cout << Solution().lexGreaterPermutation("abcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdab", "dcbadcbadcbadcbadcbadcbadcbadcbadcbadcbadcbadcbadc") << endl;
}
#endif
