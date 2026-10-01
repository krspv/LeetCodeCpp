#ifdef TASK_20
#include <ios>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
  bool isValid(const string &s) {
    vector<char> stx;
    stx.reserve(s.length() / 2);

    for (char ch : s) {
      switch (ch) {
      case '(':
      case '{':
      case '[':
        stx.push_back(ch);
        break;
      case ')':
        if (stx.empty() || stx.back() != '(')
          return false;
        stx.pop_back();
        break;
      case ']':
        if (stx.empty() || stx.back() != '[')
          return false;
        stx.pop_back();
        break;
      case '}':
        if (stx.empty() || stx.back() != '{')
          return false;
        stx.pop_back();
        break;
      }
    }

    return stx.empty();
  }
};


int main() {
  cout << boolalpha;
  cout << Solution().isValid("()") << endl;
  cout << Solution().isValid("()[]{}") << endl;
  cout << Solution().isValid("(]") << endl;
  cout << Solution().isValid("([])") << endl;
  cout << Solution().isValid("([)]") << endl;
}
#endif
