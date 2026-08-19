#ifdef TASK_6
#include <iostream>
using namespace std;


class Solution {
public:
  const string &convert(const string &s, int numRows) {
    if (numRows == 1) return s;
    ret.reserve(s.size());
    int len = static_cast<int>(s.size());
    for (int jump = numRows; jump > 0; --jump) {
      for (int pos = numRows - jump; pos < len; pos += 2* numRows - 2) {
        ret += s[pos];
        if (jump < numRows and jump > 1 and pos + 2*jump - 2 < len)
          ret += s[pos + 2*jump - 2];
      }
    }
    return ret;
  }
private:
  string ret;
};


int main() {
  cout << Solution().convert("PAYPALISHIRING", 3) << endl;
  cout << Solution().convert("PAYPALISHIRING", 4) << endl;
  cout << Solution().convert("A", 1) << endl;
  cout << Solution().convert("PAYPALISHIRING", 2) << endl;
}
#endif
