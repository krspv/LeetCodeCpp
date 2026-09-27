#ifdef TASK_1190
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <stack>
using namespace std;


class Solution {
public:
  string reverseParentheses(const string& s) {
    stack<size_t> stx;
    string ret;

    for (char ch : s) {
      switch (ch) {
      case '(': stx.push(size(ret)); break;
      case ')':
        reverse(begin(ret) + stx.top(), end(ret));  
        stx.pop();
        break;
      default: ret.push_back(ch); break;
      }
    }

    return ret;
  }
};


int main() {
  string s;

  cout << Solution().reverseParentheses("(abcd)") << endl;
  cout << Solution().reverseParentheses("(u(love)i)") << endl;
  cout << Solution().reverseParentheses("(ed(et(oc))el)") << endl;
  cout << Solution().reverseParentheses("(ni(lands)si)(eht)stream") << endl;
}
#endif
