#ifdef TASK_1563
#include <iostream>
#include <vector>
#include <memory>
using namespace std;


class Solution {
public:
  int stoneGameV(vector<int>& stoneValue) {
    arrSum.resize(stoneValue.size() + 1);

    for (int i = 0; i < stoneValue.size(); ++i)
      arrSum[i + 1] = arrSum[i] + stoneValue[i];

    int n = static_cast<int>(stoneValue.size());
    cache.assign((n + 1) * (n + 1), -1);

    return maxDivide(1, n);
  }

private:
  int maxDivide(int lbound, int rbound) {
    if (lbound == rbound)
      return 0;

    int key = lbound * static_cast<int>(arrSum.size()) + rbound;
    if (cache[key] != -1)
      return cache[key];

    int nRet = 0;
    for (int i = lbound; i < rbound; ++i) {
      int lSum = arrSum[i] - arrSum[lbound - 1];
      int rSum = arrSum[rbound] - arrSum[i];

      int val = lSum > rSum
        ? rSum + maxDivide(i + 1, rbound)
        : lSum < rSum
          ? lSum + maxDivide(lbound, i)
          : max(lSum + maxDivide(lbound, i), rSum + maxDivide(i + 1, rbound));
      if (val > nRet) nRet = val;
    }

    cache[key] = nRet;
    return nRet;
  }

  vector<int> cache, arrSum;
};


int main() {
  cout << Solution().stoneGameV(*make_unique<vector<int>>(vector{ 6, 2, 3, 4, 5, 5 })) << endl;
  cout << Solution().stoneGameV(*make_unique<vector<int>>(vector{ 7, 7, 7, 7, 7, 7, 7 })) << endl;
  cout << Solution().stoneGameV(*make_unique<vector<int>>(vector{ 4 })) << endl;
  cout << Solution().stoneGameV(*make_unique<vector<int>>(vector{ 2, 1, 1 })) << endl;
  cout << Solution().stoneGameV(*make_unique<vector<int>>(vector{ 62008, 269055, 379802, 503405, 589774 })) << endl;
  cout << Solution().stoneGameV(*make_unique<vector<int>>(vector{ 1, 10, 100, 1000, 10000 })) << endl;
}
#endif
