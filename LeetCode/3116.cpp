#ifdef TASK_3116
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


class Solution {
public:
  long long findOrdinal(const vector<int>& coins, long long value, size_t idx, long long curLcm, int depth) {
    long long total = 0;
    for (size_t i = idx; i < coins.size(); ++i) {
      long long L = lcm(curLcm, coins[i]);
      int newDepth = depth + 1;
      long long term = value / L;

      total += (newDepth % 2 == 1) ? term : -term;
      total += findOrdinal(coins, value, i + 1, L, newDepth);
    }
    return total;
  }

  long long findKthSmallest(vector<int>& coins, int k) {
    sort(begin(coins), end(coins));

    if (1 == coins[0])
      return k;

    // Reduce the vector by removing coins that are a multiple of lesser coins
    for (size_t i = 1; i < coins.size(); ++i) {
      for (size_t j = 0; j < i; ++j)
        if (coins[j] != -1 and coins[i] % coins[j] == 0) {
          coins[i] = -1;
          break;
        }
    }

    erase(coins, -1);

    if (1 == size(coins))
      return static_cast<long long>(k) * coins[0];

    long long L = 1, R = static_cast<long long>(coins.back()) * k;
    long long ordinal, mid = -1, prev_mid;
    do {
      prev_mid = mid;
      mid = L + ((R - L) >> 1);
      ordinal = findOrdinal(coins, mid, 0, 1, 0);
      if (ordinal > k)
        R = mid;
      else
        L = mid;
    } while (k != ordinal && mid != prev_mid);

    long long min_remainder = 99;
    for (int coin : coins) {
      if (mid % coin < min_remainder)
        min_remainder = mid % coin;
    }
    mid -= min_remainder;

    return mid;
  }

  long long findKthSmallestBrute(const vector<int>& coins, int k) {
    vector<long long> values(begin(coins), end(coins));
    long long next = -1;
    while (k > 0) {
      auto it = min_element(begin(values), end(values));
      int index = static_cast<int>(it - begin(values));
      if (*it != next)
        --k;
      next = *it;
      *it += coins[index];
    }
    return next;
  }

  void PrintFirstK(const vector<int>& coins, int k) {
    for (int x = 1; x < k; ++x) {
      long long out = Solution().findKthSmallestBrute(*make_unique<vector<int>>(vector{ 5, 2 }), x);
      if (x > 1) cout << ' ';
      cout << out;
    }
    cout << endl;
  }
};


int main() {
  cout << Solution().findKthSmallest(*make_unique<vector<int>>(vector{ 17, 2, 13 }), 300) << endl;
  cout << Solution().findKthSmallestBrute(*make_unique<vector<int>>(vector{ 17, 2, 13 }), 300) << endl;
  cout << Solution().findKthSmallest(*make_unique<vector<int>>(vector{ 3, 6, 9 }), 3) << endl;
  cout << Solution().findKthSmallestBrute(*make_unique<vector<int>>(vector{ 3, 6, 9 }), 3) << endl;
  cout << Solution().findKthSmallest(*make_unique<vector<int>>(vector{ 5, 2 }), 359876) << endl;
  cout << Solution().findKthSmallestBrute(*make_unique<vector<int>>(vector{ 5, 2 }), 359876) << endl;
  cout << Solution().findKthSmallest(*make_unique<vector<int>>(vector{ 5, 2 }), 7) << endl;
  cout << Solution().findKthSmallestBrute(*make_unique<vector<int>>(vector{ 5, 2 }), 7) << endl;
  cout << Solution().findKthSmallest(*make_unique<vector<int>>(vector{ 5, 2 }), 1) << endl;
  cout << Solution().findKthSmallestBrute(*make_unique<vector<int>>(vector{ 5, 2 }), 1) << endl;
  cout << Solution().findKthSmallest(*make_unique<vector<int>>(vector{ 5, 2 }), 2) << endl;
  cout << Solution().findKthSmallestBrute(*make_unique<vector<int>>(vector{ 5, 2 }), 2) << endl;
  cout << Solution().findKthSmallest(*make_unique<vector<int>>(vector{ 5, 2 }), 3) << endl;
  cout << Solution().findKthSmallestBrute(*make_unique<vector<int>>(vector{ 5, 2 }), 3) << endl;
  cout << Solution().findKthSmallest(*make_unique<vector<int>>(vector{ 17, 22, 25, 24 }), 3000) << endl;
  cout << Solution().findKthSmallestBrute(*make_unique<vector<int>>(vector{ 17, 22, 25, 24 }), 3000) << endl;
  cout << Solution().findOrdinal(*make_unique<vector<int>>(vector{ 5, 2 }), 7, 0, 1, 0) << endl;
}
#endif
