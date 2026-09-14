#ifdef TASK_3414
#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <vector>
#include "json.hpp"
using json = nlohmann::json;
using namespace std;


class Solution {
public:
  struct Sel {
    long long score = 0;
    int cnt = 0;
    array<int, 4> idx{}; // sorted ascending original indices
  };

  // true if a is strictly better than b (higher score, then lexicographically smaller idx list)
  static bool better(const Sel& a, const Sel& b) {
    if (a.score != b.score) return a.score > b.score;
    int m = min(a.cnt, b.cnt);
    for (int i = 0; i < m; ++i)
      if (a.idx[i] != b.idx[i]) return a.idx[i] < b.idx[i];
    return a.cnt < b.cnt; // prefix rule: shorter list wins a tie
  }

  vector<int> maximumWeight(vector<vector<int>>& intervals) {
    int n = static_cast<int>(intervals.size());
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    stable_sort(order.begin(), order.end(), [&](int a, int b) {
      return intervals[a][0] < intervals[b][0];
      });

    vector<int> L(n), R(n), W(n);
    for (int i = 0; i < n; ++i) {
      L[i] = intervals[order[i]][0];
      R[i] = intervals[order[i]][1];
      W[i] = intervals[order[i]][2];
    }

    // nxt[i] = first index j with L[j] > R[i]
    vector<int> nxt(n);
    for (int i = 0; i < n; ++i)
      nxt[i] = static_cast<int>(upper_bound(L.begin(), L.end(), R[i]) - L.begin());

    vector<vector<Sel>> dp(n + 1, vector<Sel>(5)); // dp[n][*] and dp[*][0] default to {0,0,{}}

    for (int i = n - 1; i >= 0; --i) {
      for (int k = 1; k <= 4; ++k) {
        Sel skip = dp[i + 1][k];

        Sel take = dp[nxt[i]][k - 1];
        take.score += W[i];
        int pos = 0;
        while (pos < take.cnt && take.idx[pos] < order[i]) ++pos;
        for (int p = take.cnt; p > pos; --p) take.idx[p] = take.idx[p - 1];
        take.idx[pos] = order[i];
        take.cnt += 1;

        dp[i][k] = better(take, skip) ? take : skip;
      }
    }

    Sel best = dp[0][4];
    return vector<int>(best.idx.begin(), best.idx.begin() + best.cnt);
  }
};


static void printVec(const vector<int>& vec) {
  if (size(vec) > 0) cout << vec[0];
  for (int val : vec | views::drop(1))
    cout << ", " << val;
  cout << endl;
}


int main() {
  ifstream file("input_3414.json");
  json j;
  vector<vector<int>> intervals;
  file >> j;

  intervals = j["case1"].get<vector<vector<int>>>();
  printVec(Solution().maximumWeight(intervals));

  intervals = j["case2"].get<vector<vector<int>>>();
  printVec(Solution().maximumWeight(intervals));

  intervals = j["case3"].get<vector<vector<int>>>();
  printVec(Solution().maximumWeight(intervals));

  intervals = j["case4"].get<vector<vector<int>>>();
  printVec(Solution().maximumWeight(intervals));

  intervals = j["case5"].get<vector<vector<int>>>();
  printVec(Solution().maximumWeight(intervals));

  intervals = j["case6"].get<vector<vector<int>>>();
  printVec(Solution().maximumWeight(intervals));

  intervals = j["case7"].get<vector<vector<int>>>();
  printVec(Solution().maximumWeight(intervals));

  intervals = j["case8"].get<vector<vector<int>>>();
  printVec(Solution().maximumWeight(intervals));
}
#endif
