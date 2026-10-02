#ifdef TASK_22
#include <array>
#include <iostream>
#include <iterator>
#include <string>
#include <set>
#include <vector>
using namespace std;


class Solution {
public:
  vector<string> generateParenthesis(int n) {
    if (m_all[0].empty()) {
      m_all[0].push_back("()");
      for (int i = 0; i < 7; ++i) {
        int L = static_cast<int>(size(m_all[i]));
        set<string> sx;
        for (int l = 0; l < L; ++l) {
          const string &work_string = m_all[i][l];
          int P = static_cast<int>(work_string.length());
          for (int p = 0; p < P; ++p) {
            string candidate = work_string.substr(0, p) + "()" + work_string.substr(p);
            sx.insert(candidate);
          }
        }
        m_all[i + 1].insert(end(m_all[i + 1]), begin(sx), end(sx));
      }
    }
    return m_all[n - 1];
  }
private:
  static array<vector<string>, 8> m_all;
};
array<vector<string>, 8> Solution::m_all;


template <typename T>
static void printVec(const vector<T>& vec) {
  for (const T& item : vec)
    cout << item << ' ';
  cout << endl;
}


int main() {
  printVec(Solution().generateParenthesis(1));
  printVec(Solution().generateParenthesis(2));
  printVec(Solution().generateParenthesis(3));
}
#endif
