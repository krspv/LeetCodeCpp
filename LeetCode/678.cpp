#ifdef TASK_678
#include <ios>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_set>
using namespace std;


class Solution {
private:
  struct Pos {
    int before, after;
    bool open;
  };
  bool chkValid(int start, int count, const string& s, int L) {
    if (count < 0) return false;

    while (start < L) {
      if (s[start] == '(') {
        ++count, ++start;
      }
      else if (s[start] == ')') {
        --count, ++start;
        if (count < 0) return false;
      }
      else {
        return chkValid(start + 1, count + 1, s, L) or chkValid(start + 1, count - 1, s, L) or chkValid(start + 1, count, s, L);
      }
    }

    return count == 0;
  }

public:
  bool checkValidString(const string& s) {
    //if (s.find('(') == string::npos && s.find(')') == string::npos) return true;
    //return chkValid(0, 0, s, static_cast<int>(s.length()));
    unordered_set<int> counter{ 0 }, temp;
    for (char ch : s) {
      if (ch == '(') {
        temp.clear();
        for (int i : counter) temp.insert(i + 1);
        counter = temp;
      }
      else if (ch == ')') {
        temp.clear();
        for (int i : counter) if (i-1 >= 0) temp.insert(i - 1);
        counter = temp;
      }
      else {
        temp.clear();
        for (int i : counter) {
          temp.insert(i + 1);
          if (i - 1 >= 0) temp.insert(i - 1);
        }
        counter.insert(begin(temp), end(temp));
      }
      if (counter.empty()) return false;
    }
    return counter.contains(0);
  }
};


int main() {
  cout << boolalpha;
  cout << Solution().checkValidString("()") << endl;
  cout << Solution().checkValidString("(*)") << endl;
  cout << Solution().checkValidString("(*))") << endl;
  cout << Solution().checkValidString("(") << endl;
  cout << Solution().checkValidString("((**())") << endl;
  cout << Solution().checkValidString("**************************************************))))))))))))))))))))))))))))))))))))))))))))))))))") << endl;
  cout << Solution().checkValidString("************************************************************") << endl;
}
#endif
