#ifdef TASK_835
#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <iterator>
#include <unordered_set>
#include <vector>
#include "json.hpp"
using json = nlohmann::json;
using namespace std;


class Solution {
public:
  int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
    int n = static_cast<int>(size(img1));

    unordered_set<int> setOnesImg2;
    for (int row = 0; row < n; ++row) {
      const auto& line = img2[row];
      for (int col = 0; col < n; ++col)
        if (line[col])
          setOnesImg2.insert(100 * row + col);
    }

    vector<array<int, 2>> onesImg1;
    int maxShiftR(0), maxShiftB(0), maxShiftL(0), maxShiftU(0);
    for (int row = 0; row < n; ++row) {
      const auto& line = img1[row];
      bool bRowHasOnes = false;
      for (int col = 0; col < n; ++col)
        if (line[col]) {
          onesImg1.push_back(array{ row, col });
          maxShiftR = max(maxShiftR, n - 1 - col);
          maxShiftL = min(maxShiftL, -col);
          bRowHasOnes = true;
        }
      if (bRowHasOnes) {
        maxShiftB = max(maxShiftB, n - 1 - row);
        maxShiftU = min(maxShiftU, -row);
      }
    }

    int nMinSize = static_cast<int>(min(size(setOnesImg2), size(onesImg1)));
    if (nMinSize == 0) return 0;

    int maxOverlap(0), count;
    for (int rowShift = maxShiftU; rowShift <= maxShiftB; ++rowShift)
      for (int colShift = maxShiftL; colShift <= maxShiftR; ++colShift) {
        count = 0;
        for (auto& arr : onesImg1) {
          int row = arr[0] + rowShift;
          int col = arr[1] + colShift;
          if (row >= 0 && col >= 0 && row < n && col < n && setOnesImg2.contains(100 * row + col)) ++count;
        }
        maxOverlap = max(maxOverlap, count);
        if (maxOverlap == nMinSize) return maxOverlap;
      }

    return maxOverlap;
  }
  
  // AI solution (Claude)
  int largestOverlapAI(vector<vector<int>>& img1, vector<vector<int>>& img2) {
    int n = static_cast<int>(size(img1));

    vector<array<int, 2>> ones1, ones2;
    for (int r = 0; r < n; ++r)
      for (int c = 0; c < n; ++c) {
        if (img1[r][c]) ones1.push_back({ r, c });
        if (img2[r][c]) ones2.push_back({ r, c });
      }

    if (empty(ones1) or empty(ones2)) return 0;

    int span = 2 * n - 1;
    vector<int> shiftCount(span * span, 0);
    int nMaxOverlap = 0;
    int nMinSize = static_cast<int>(min(ones1.size(), ones2.size()));

    for (const auto& p1 : ones1)
      for (const auto& p2 : ones2) {
        int idx = (p2[0] - p1[0] + n - 1) * span + (p2[1] - p1[1] + n - 1);
        if (++shiftCount[idx] > nMaxOverlap) {
          nMaxOverlap = shiftCount[idx];
          if (nMaxOverlap == nMinSize) return nMaxOverlap;
        }
      }

    return nMaxOverlap;
  }
};


int main() {
  ifstream file("input_835.json");
  json j;
  vector<vector<int>> img1, img2;
  file >> j;

  img1 = j["case1"]["img1"].get<vector<vector<int>>>();
  img2 = j["case1"]["img2"].get<vector<vector<int>>>();
  cout << Solution().largestOverlapAI(img1, img2) << endl;

  //img1 = j["case2"]["img1"].get<vector<vector<int>>>();
  //img2 = j["case2"]["img2"].get<vector<vector<int>>>();
  //cout << Solution().largestOverlapAI(img1, img2) << endl;

  //img1 = j["case3"]["img1"].get<vector<vector<int>>>();
  //img2 = j["case3"]["img2"].get<vector<vector<int>>>();
  //cout << Solution().largestOverlapAI(img1, img2) << endl;
}
#endif
