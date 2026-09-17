#ifdef TASK_1477
#include <fstream>
#include <iostream>
#include <iterator>
#include <memory>
#include <numeric>
#include <utility>
#include <vector>
#include "json.hpp"
using json = nlohmann::json;
using namespace std;


class Solution {
public:
  int minSumOfLengths(vector<int>& arr, int target) {
    partial_sum(begin(arr), end(arr), begin(arr));
    vector<pair<int, int>> bestBefore;

    int theBest = -1, idxBest = 0;

    const int L = static_cast<int>(size(arr));
    int minJ = 0;
    for (int i = 0; i < L; ++i) {
      int cur = arr[i];
      if (cur == target)
        bestBefore.push_back(make_pair(i, i + 1));
      else if (cur > target) {
        int j = minJ;
        while (cur - arr[j] > target) ++j;
        minJ = j;
        if (cur - arr[j] == target) {
          int lastBest = bestBefore.empty() ? (i + 1) : bestBefore.back().second;
          if (i - j < lastBest)
            bestBefore.push_back(make_pair(i, i - j));
          const int LB = static_cast<int>(size(bestBefore)) - 1;
          while (bestBefore[idxBest].first <= j) {
            if (theBest == -1 || (theBest > bestBefore[idxBest].second + i - j))
              theBest = bestBefore[idxBest].second + i - j;
            if (idxBest == LB) break;
            ++idxBest;
          }
        }
      }
    }

    return theBest;
  }
};


int main() {
  cout << Solution().minSumOfLengths(*make_unique<vector<int>>(vector{ 1, 1, 1, 1, 2, 2, 70, 70, 4, 2 }), 4) << endl;
  cout << Solution().minSumOfLengths(*make_unique<vector<int>>(vector{ 3, 2, 2, 4, 3 }), 3) << endl;
  cout << Solution().minSumOfLengths(*make_unique<vector<int>>(vector{ 7, 3, 4, 7 }), 7) << endl;
  cout << Solution().minSumOfLengths(*make_unique<vector<int>>(vector{ 4, 3, 2, 6, 2, 3, 4 }), 6) << endl;
  cout << Solution().minSumOfLengths(*make_unique<vector<int>>(vector{ 33, 13, 1, 1, 34, 11, 1, 2, 14, 21, 12, 1, 20, 23, 5, 28, 7, 13, 16, 21, 2, 2, 2, 3, 2, 45, 2, 1, 11, 37, 21, 27, 17, 1, 23, 2 }), 48) << endl;

  ifstream file("input_1477.json");
  json j;
  vector<int> vec;
  int tgt;
  file >> j;

  vec= j["case1"]["arr"].get<vector<int>>();
  tgt = j["case1"]["tgt"].get<int>();
  cout << Solution().minSumOfLengths(vec, tgt) << endl;

  vec = j["case2"]["arr"].get<vector<int>>();
  tgt = j["case2"]["tgt"].get<int>();
  cout << Solution().minSumOfLengths(vec, tgt) << endl;

  vec = j["case3"]["arr"].get<vector<int>>();
  tgt = j["case3"]["tgt"].get<int>();
  cout << Solution().minSumOfLengths(vec, tgt) << endl;
}
#endif
