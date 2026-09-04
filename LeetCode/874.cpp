#ifdef TASK_874
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <type_traits>
#include <vector>
using namespace std;


class Solution {
private:
  enum EDirection { North = 0, East, South, West };
public:
  int robotSim(vector<int>& commands, vector<vector<int>>& sortedX) {
    int xPos = 0, yPos = 0, maxDist = 0;
    EDirection dir = EDirection::North;

    // Sort by x then by y
    sort(begin(sortedX), end(sortedX), [](const auto& lhs, const auto& rhs) { return rhs.front() == lhs.front() ? rhs.back() > lhs.back() : rhs.front() > lhs.front(); });
    // Make a copy
    vector<reference_wrapper<vector<int>>> sortedY(begin(sortedX), end(sortedX));
    // Sort by y then by x
    sort(begin(sortedY), end(sortedY), [](const auto& lhs, const auto& rhs) { return rhs.get().back() == lhs.get().back() ? rhs.get().front() > lhs.get().front() : rhs.get().back() > lhs.get().back(); });

    for (int command : commands) {
      switch (command) {
      case -2:
        dir = dir == EDirection::North ? EDirection::West : EDirection(dir - 1);
        break;

      case -1:
        dir = dir == EDirection::West ? EDirection::North : EDirection(dir + 1);
        break;

      default:
        switch (dir) {
        case EDirection::East:
          {
            int xEnd = xPos + command;
            auto lo = lower_bound(cbegin(sortedY), cend(sortedY), yPos, [](const auto& elem, int val) { return elem.get().back() < val; });
            if (lo != end(sortedY)) {
              auto hi = upper_bound(cbegin(sortedY), cend(sortedY), yPos, [](int val, const auto& elem) { return val < elem.get().back(); });
              if (lo != hi) {
                auto nx = upper_bound(lo, hi, xPos, [](int val, const auto& elem) { return val < elem.get().front(); });
                if (nx != hi) {
                  xEnd = min(xEnd, nx->get().front() - 1);
                }
              }
            }
            xPos = xEnd;
          }
          break;
        case EDirection::West:
          {
            int xEnd = xPos - command;
            auto lo = lower_bound(cbegin(sortedY), cend(sortedY), yPos, [](const auto& elem, int val) { return elem.get().back() < val; });
            if (lo != end(sortedY)) {
              auto hi = upper_bound(cbegin(sortedY), cend(sortedY), yPos, [](int val, const auto& elem) { return val < elem.get().back(); });
              if (lo != hi) {
                auto nx = lower_bound(lo, hi, xPos, [](const auto& elem, int val) { return elem.get().front() < val; });
                if (nx > lo) {
                  xEnd = max(xEnd, prev(nx)->get().front() + 1);
                }
              }
            }
            xPos = xEnd;
          }
          break;
        case EDirection::North:
          {
            int yEnd = yPos + command;
            auto lo = lower_bound(cbegin(sortedX), cend(sortedX), xPos, [](const auto& elem, int val) { return elem.front() < val; });
            if (lo != end(sortedX)) {
              auto hi = upper_bound(cbegin(sortedX), cend(sortedX), xPos, [](int val, const auto& elem) { return val < elem.front(); });
              if (lo != hi) {
                auto nx = upper_bound(lo, hi, yPos, [](int val, const auto& elem) { return val < elem.back(); });
                if (nx != hi) {
                  yEnd = min(yEnd, nx->back() - 1);
                }
              }
            }
            yPos = yEnd;
          }
          break;
        case EDirection::South:
          {
            int yEnd = yPos - command;
            auto lo = lower_bound(cbegin(sortedX), cend(sortedX), xPos, [](const auto& elem, int val) { return elem.front() < val; });
            if (lo != end(sortedX)) {
              auto hi = upper_bound(cbegin(sortedX), cend(sortedX), xPos, [](int val, const auto& elem) { return val < elem.front(); });
              if (lo != hi) {
                auto nx = lower_bound(lo, hi, yPos, [](const auto& elem, int val) { return elem.back() < val; });
                if (nx > lo) {
                  yEnd = max(yEnd, prev(nx)->back() + 1);
                }
              }
            }
            yPos = yEnd;
          }
        break;
        }
        maxDist = max(maxDist, xPos * xPos + yPos * yPos);
        break;
      }
    }
    return maxDist;
  }
};


int main() {
  cout << Solution().robotSim(*make_unique<vector<int>>(vector{ 4, -1, 3 }), *make_unique<vector<vector<int>>>(vector<vector<int>>{})) << endl;
  cout << Solution().robotSim(*make_unique<vector<int>>(vector{ 4, -1, 4, -2, 4 }), *make_unique<vector<vector<int>>>(vector<vector<int>>{ vector{2, 4} })) << endl;
  cout << Solution().robotSim(*make_unique<vector<int>>(vector{ 6, -1, -1, 6 }), *make_unique<vector<vector<int>>>(vector<vector<int>>{ vector{ 0, 0 } })) << endl;
}
#endif
