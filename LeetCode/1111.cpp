#ifdef TASK_1111
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
  vector<int> maxDepthAfterSplit(const string& seq) {
    vector<int> ret;
    ret.reserve(seq.length());
    int nDepth = 0;

    for (char ch : seq) {
      if (ch == '(')
        ret.push_back(nDepth++ % 2);
      else
        ret.push_back(--nDepth % 2);
    }

    return ret;
  }
};


template <typename T>
static void printVec(const vector<T>& vec) {
  for (const T& item : vec)
    cout << item << ' ';
  cout << endl;
}


int main() {
  printVec(Solution().maxDepthAfterSplit("(()())"));
  printVec(Solution().maxDepthAfterSplit("()(())()"));
}
#endif
