#ifdef TASK_10
#include <format>
#include <ios>
#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
  bool isMatch(const string &s, const string &p) {
    string p1 = simplify(p);
    return stepMatch(s, p1, 0, 0);
  }

private:
  string simplify(const string& p) {
    string ret = p;
    size_t pos = -1;

    while (true) {
      pos = ret.find('*', pos + 1);
      if (pos == string::npos) break;
      if (ret[pos - 1] != '.') {
        size_t pos2 = pos + 2;
        while (pos2 < ret.length() && ret[pos2] == '*' && ret[pos2 - 1] == ret[pos - 1])
          ret.replace(pos-1, 4, format("{}*", ret[pos - 1]));
      }
      else {
        size_t posFirst = pos - 1;
        while (posFirst > 1 && ret[posFirst - 1] == '*') posFirst -= 2;
        size_t posLast = pos + 1;
        while (posLast < ret.length() - 1 && ret[posLast + 1] == '*') posLast += 2;
        if (posFirst < pos - 1 || posLast > pos + 1) {
          ret.replace(posFirst, posLast - posFirst, ".*");
          pos = posFirst + 1;
        }
      }
    }

    return ret;
  }

  bool stepMatch(const string& s, const string& p, size_t idxS, size_t idxP) {
    if (s.length() == idxS) {
      while (idxP < p.length() - 1 && p[idxP + 1] == '*') idxP += 2;
      return idxP == p.length();
    }
    if (p.length() == idxP) return false;

    string ss = s.substr(idxS);
    string pp = p.substr(idxP);

    char stringCh = s[idxS];
    char patternCh = p[idxP];
    bool bNextIsStar = idxP < p.length() - 1 && p[idxP + 1] == '*';

    if (patternCh == stringCh || patternCh == '.')
      if (bNextIsStar) {
        return stepMatch(s, p, idxS + 1, idxP) || stepMatch(s, p, idxS + 1, idxP + 2) || stepMatch(s, p, idxS, idxP + 2);
      } else
        return stepMatch(s, p, idxS + 1, idxP + 1);
    else if (bNextIsStar)
      return stepMatch(s, p, idxS, idxP + 2);

    return false;
  }
};


int main() {
  cout << boolalpha;
  cout << Solution().isMatch("aa", "a") << endl;
  cout << Solution().isMatch("aa", "a*") << endl;
  cout << Solution().isMatch("ab", ".*") << endl;
  cout << Solution().isMatch("aab", "c*a*b") << endl;
  cout << Solution().isMatch("aaa", "ab*a*c*a") << endl;
  cout << Solution().isMatch("ab", ".*c") << endl;
  cout << Solution().isMatch("bbbba", ".*a*a") << endl;
  cout << Solution().isMatch("aaaaaaaaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*") << endl;
}
#endif
