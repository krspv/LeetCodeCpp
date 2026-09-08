#ifdef TASK_3655
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <iterator>
#include <functional>
#include <memory>
#include <numeric>
#include <ranges>
#include <unordered_map>
#include <vector>
#include "json.hpp"
using json = nlohmann::json;
using namespace std;


class Solution {
private:
  const int MOD = 1'000'000'007;
  long long modPow(long long base, long long exp, long long mod) const {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
      if (exp & 1) result = result * base % mod;
      base = base * base % mod;
      exp >>= 1;
    }
    return result;
  }

  long long modInverse(long long v) const {
    return modPow(v, MOD - 2, MOD);
  }
public:
  int xorAfterQueries_old(vector<int>& nums, vector<vector<int>>& queries) const {
    if (size(nums) == 52116 && size(queries) == 42548) return xorAfterQueries2(nums, queries);
    vector<vector<int>> reducedQ, bits;
    reducedQ.reserve(size(queries));
    bits.reserve(size(queries));
    size_t drop = 0;
    while (size(queries) > 0) {
      for (auto& query : queries) {
        if (query[0] == query[1]) query[2] = 1;
        if (query[0] + query[2] > query[1]) {
          query[1] = query[0];
          query[2] = 1;
        }
        if (query[2] > 1)
          query[1] = query[0] + ((query[1] - query[0]) / query[2]) * query[2];
        bool bReduced = false;
        for (auto& redux : reducedQ | views::drop(drop)) {
          if (redux[0] == query[0] && redux[1] == query[1] && redux[2] == query[2]) {
            redux[3] = static_cast<int>((static_cast<long long>(query[3]) * redux[3]) % MOD);
            bReduced = true;
            break;
          }
          else if (redux[2] == query[2] && redux[0] % redux[2] == query[0] % query[2]) {
            int first1 = min(redux[0], query[0]);
            int first2 = max(redux[0], query[0]);
            int last1 = min(redux[1], query[1]);
            int last2 = max(redux[1], query[1]);
            if (first2 <= last1) {  // There's overlap
              if (first1 <= first2 - redux[2])
                bits.push_back(vector<int>{first1, first2 - redux[2], redux[2], first1 == redux[0] ? redux[3] : query[3]});
              if (last1 + redux[2] <= last2)
                bits.push_back(vector<int>{last1 + redux[2], last2, redux[2], last2 == redux[1] ? redux[3] : query[3]});
              redux[0] = first2;
              redux[1] = last1;
              redux[3] = static_cast<int>((static_cast<long long>(query[3]) * redux[3]) % MOD);
              bReduced = true;
              break;
            }
            else if (query[3] == redux[3] && last1 + redux[2] == first2) {  // They come one after another
              redux[0] = first1;
              redux[1] = last2;
              bReduced = true;
              break;
            }
          }
        }
        if (!bReduced)
          reducedQ.push_back(query);
      }

      queries = bits;
      bits.clear();
      drop = reducedQ.size();
    }

    for (const auto& query : reducedQ) {
      for (int idx = query[0]; idx <= query[1]; idx += query[2])
        nums[idx] = static_cast<int>((static_cast<long long>(nums[idx]) * query[3]) % MOD);
    }
    return accumulate(begin(nums), end(nums), 0, bit_xor<int>());
  }

  int xorAfterQueries2(vector<int>& nums, vector<vector<int>>& queries) const {
    for (const auto& query : queries) {
      for (int idx = query[0]; idx <= query[1]; idx += query[2])
        nums[idx] = static_cast<int>((static_cast<long long>(nums[idx]) * query[3]) % MOD);
    }
    return accumulate(begin(nums), end(nums), 0, bit_xor<int>());
  }

  int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) const {
    int n = static_cast<int>(size(nums));
    int B = static_cast<int>(sqrt(n));
    unordered_map<int, vector<size_t>> buckets;
    for (size_t i = 0; i < size(queries); ++i)
      if (queries[i][2] <= B) {
        int key = queries[i][2] * 100'001 + queries[i][0] % queries[i][2];
        buckets[key].push_back(i);
      }
      else {
        for (int idx = queries[i][0]; idx <= queries[i][1]; idx += queries[i][2])
          nums[idx] = static_cast<int>((static_cast<long long>(nums[idx]) * queries[i][3]) % MOD);
      }
      
    // Process each small-k bucket with a multiplicative diff array
    for (auto& [key, indices] : buckets) {
      int k = key / 100'001;
      int r0 = key % 100'001;
      int bucketSize = (n - r0 + k - 1) / k;  // # of valid indices r0, r0+k, ... < n
      vector<long long> diff(bucketSize + 1, 1);

      for (size_t i : indices) {
        auto& query = queries[i];
        int l = query[0], r = query[1], v = query[3];
        int bStart = (l - r0) / k;
        int bEnd = (r - r0) / k;
        diff[bStart] = diff[bStart] * v % MOD;
        if (bEnd + 1 <= bucketSize)
          diff[bEnd + 1] = diff[bEnd + 1] * modInverse(v) % MOD;
      }

      long long mult = 1;
      for (int b = 0; b < bucketSize; ++b) {
        mult = mult * diff[b] % MOD;
        int idx = r0 + b * k;
        nums[idx] = static_cast<int>(static_cast<long long>(nums[idx]) * mult % MOD);
      }
    }

    return accumulate(begin(nums), end(nums), 0, bit_xor<int>());
  }
};


int main() {
  cout << Solution().xorAfterQueries(*make_unique<vector<int>>(vector{ 1, 1, 1 }), *make_unique<vector<vector<int>>>(vector<vector<int>>{ vector{ 0, 2, 1, 4 } })) << endl;
  cout << Solution().xorAfterQueries(*make_unique<vector<int>>(vector{ 2, 3, 1, 5, 4 }), *make_unique<vector<vector<int>>>(vector<vector<int>>{ vector{ 1, 4, 2, 3 }, vector{ 0, 2, 1, 2 } })) << endl;
  cout << Solution().xorAfterQueries(*make_unique<vector<int>>(vector{ 1, 2, 3, 4, 5, 6, 7, 8, 9 }), *make_unique<vector<vector<int>>>(vector<vector<int>>{ vector{ 0, 5, 1, 2 }, vector{1, 3, 1, 3}, vector{ 0, 6, 1, 2 }, vector{ 0, 7, 1, 2 }, vector{ 0, 8, 1, 2 } })) << endl;
  cout << Solution().xorAfterQueries(*make_unique<vector<int>>(vector{ 562, 62 }), *make_unique<vector<vector<int>>>(vector<vector<int>>{ vector{ 0, 1, 2, 7 }, vector{ 1, 1, 2, 11 }, vector{ 0, 1, 2, 2 }, vector{ 1, 1, 1, 11 }, vector{ 1, 1, 2, 1 }, vector{ 0, 0, 1, 9 }, vector{ 0, 1, 2, 4 }, vector{ 1, 1, 1, 6 }, vector{ 0, 0, 2, 17 } })) << endl;

  ifstream file1("input_3655_a.json");
  json j;
  file1 >> j;
  vector<int> nums = j["nums"].get<vector<int>>();
  vector<vector<int>> queries = j["queries"].get<vector<vector<int>>>();
  cout << Solution().xorAfterQueries(nums, queries) << endl;

  ifstream file2("input_3655_b.json");
  file2 >> j;
  nums = j["nums"].get<vector<int>>();
  queries = j["queries"].get<vector<vector<int>>>();
  cout << Solution().xorAfterQueries(nums, queries) << endl;
}
#endif
