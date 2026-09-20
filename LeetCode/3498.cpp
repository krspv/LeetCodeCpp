#ifdef TASK_3498
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
using namespace std;


class Solution {
public:
  int reverseDegree(const string& s) {
    return accumulate(begin(s), end(s), 0, [idx = 0](int sum, char ch) mutable { return sum + ++idx * (26 - (ch - 'a')); });
  }
};


int main() {
  cout << Solution().reverseDegree("abc") << endl;
  cout << Solution().reverseDegree("zaza") << endl;
  cout << Solution().reverseDegree("abcdefghijklmnopqrstuvwxyz") << endl;
}
#endif
