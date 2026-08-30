#ifdef TASK_3734
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <utility>
using namespace std;


class Solution {
public:
  string lexGreaterPermutation(const string& s, const string& target) {
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

  string lexPalindromicPermutation(const string& s, const string& target) {
    int count[26] = { 0 };
    for (char c : s) ++count[c - 'a'];

    int nOddId = -1;
    for (int i = 0; i < 26; ++i)
      if (1 == count[i] % 2) {
        if (nOddId > -1) return "";
        nOddId = i;
      }

    const int L = static_cast<int>(s.length());
    const int HalfL = L / 2;
    string target1 = target.substr(0, HalfL);
    string s1(HalfL, ' ');
    int pos = 0;
    for (int i = 0; i < 26; ++i)
      while (count[i] > 1) {
        s1[pos++] = 'a' + i;
        count[i] -= 2;
      }

    // Test special case
    string a = s1, b = target1;
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    if (a == b) {
      string test = target1;
      if (nOddId > -1)
        test += 'a' + nOddId;
      test += string(target1.rbegin(), target1.rend());
      if (test > target)
        return test;
    }


    string t1 = lexGreaterPermutation(s1, target1);
    string out = (t1.empty()) ? string(s1.rbegin(), s1.rend()) : t1;
    if (nOddId > -1)
      out += 'a' + nOddId;
    out += string(t1.rbegin(), t1.rend());
    
    return out > target ? out : "";
  }
};


int main() {
  cout << Solution().lexPalindromicPermutation("babac", "abcba") << endl;
  cout << Solution().lexPalindromicPermutation("bcaba", "bbcaa") << endl;
  cout << Solution().lexPalindromicPermutation("abc", "abb") << endl;
  cout << Solution().lexPalindromicPermutation("aaabbbb", "abaaaaa") << endl;
  cout << Solution().lexPalindromicPermutation("racecar", "zzzzzzz") << endl;
  cout << Solution().lexPalindromicPermutation("nonkvkv", "smncqht") << endl;
  cout << Solution().lexPalindromicPermutation("dqnddndq", "ewvwkmjg") << endl;
  cout << Solution().lexPalindromicPermutation("nggnnnggnng", "gnnnnngnggn") << endl;
  cout << Solution().lexPalindromicPermutation("iuqqeileqididuldd", "diuleiiixqlduddeq") << endl;
  cout << Solution().lexPalindromicPermutation("aba", "bab") << endl;
  cout << Solution().lexPalindromicPermutation("aabb", "abaa") << endl;
}
#endif
