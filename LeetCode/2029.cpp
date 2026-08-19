#ifdef TASK_2029
#include <iostream>
#include <vector>
#include <memory>
#include <array>
using namespace std;


class Solution {
public:
  bool stoneGameIX(vector<int>& stones) {
    array<int, 3> counts{ 0, 0, 0 };
    for (int stone : stones)
      ++counts[stone % 3];
    if (stones.size() == 1) return false;
    counts[0] %= 2;
    int k = counts[1] - counts[2];
    if (k < 0) k = -k;
    if ((!counts[1] || !counts[2]) && (k == 2)) return false;
    if ((!counts[1] && (counts[2] < 2)) || (!counts[2] && (counts[1] < 2))) return false;
    if (!counts[0] && !counts[1] && counts[2] > 2) return false;
    if (!counts[0] && !counts[2] && counts[1] > 2) return false;
    if (k == 0) return counts[0] == 0;
    if (counts[0] && k == 2) return false;
    return k - counts[0] > 0;
  }
};


int main() {
  cout << boolalpha;
  cout << Solution().stoneGameIX(*make_unique<vector<int>>(vector{ 1, 2 })) << endl;
  cout << Solution().stoneGameIX(*make_unique<vector<int>>(vector{ 2 })) << endl;
  cout << Solution().stoneGameIX(*make_unique<vector<int>>(vector{ 5, 1, 2, 4, 3 })) << endl;
  cout << Solution().stoneGameIX(*make_unique<vector<int>>(vector{ 2, 3 })) << endl;
  cout << Solution().stoneGameIX(*make_unique<vector<int>>(vector{ 3, 12, 15, 20, 20, 17, 2, 17, 4 })) << endl;
  cout << Solution().stoneGameIX(*make_unique<vector<int>>(vector{ 19, 2, 17, 20, 7, 17 })) << endl;
  cout << Solution().stoneGameIX(*make_unique<vector<int>>(vector{ 1, 11, 12, 17, 6 })) << endl;
  cout << Solution().stoneGameIX(*make_unique<vector<int>>(vector{ 2, 2, 3 })) << endl;
  cout << Solution().stoneGameIX(*make_unique<vector<int>>(vector{ 15, 20, 10, 13, 14, 15, 5, 2, 3 })) << endl;
  cout << Solution().stoneGameIX(*make_unique<vector<int>>(vector{ 2, 3, 2, 2 })) << endl;
  cout << Solution().stoneGameIX(*make_unique<vector<int>>(vector{ 3, 3, 1 })) << endl;
  cout << Solution().stoneGameIX(*make_unique<vector<int>>(vector{ 3, 9, 1, 1, 1, 7, 9 })) << endl;
  cout << Solution().stoneGameIX(*make_unique<vector<int>>(vector{ 10000, 10000, 10000, 10000, 10000, 10000 })) << endl;
}
#endif
