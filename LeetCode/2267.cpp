#ifdef TASK_2267
#include <bitset>
#include <ios>
#include <iostream>
#include <iterator>
#include <unordered_set>
#include <vector>
using namespace std;

#define RUN cout << Solution().hasValidPathAI(grid) << endl


class Solution {
public:
  bool hasValidPath(vector<vector<char>>& grid) {
    int R = static_cast<int>(size(grid));
    int C = static_cast<int>(size(grid[0]));
    vector<vector<unordered_set<int>>> gx(R, vector<unordered_set<int>>(C));

    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        if (r == 0 && c == 0) {
          if (grid[r][c] == ')') return false;
          else gx[r][c].insert(1);
        }
        else {
          int value = grid[r][c] == '(' ? 1 : -1;
          int remaining = R + C - r - c - 2;
          if (r > 0)
            for (int prv : gx[r - 1][c]) {
              int nxt = prv + value;
              if (nxt >= 0 && nxt <= remaining)
                gx[r][c].insert(nxt);
            }
          if (c > 0)
            for (int prv : gx[r][c - 1]) {
              int nxt = prv + value;
              if (nxt >= 0 && nxt <= remaining)
                gx[r][c].insert(nxt);
            }
        }
      }
    }

    return gx[R - 1][C - 1].contains(0);
  }

  bool hasValidPathAI(vector<vector<char>>& grid) {
    int R = static_cast<int>(size(grid)), C = static_cast<int>(size(grid[0]));

    // Quick rejections
    if ((R + C - 1) % 2 != 0) return false;            // odd path length
    if (grid[0][0] == ')' || grid[R - 1][C - 1] == '(') return false;

    using BS = bitset<101>;   // balance never needs to exceed 100
    vector<BS> dp(C);         // one row only: dp[c] holds row r-1 until overwritten

    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        BS in;
        if (r == 0 && c == 0) in[0] = 1;               // balance 0 before first cell
        else {
          if (r > 0) in |= dp[c];                       // from above (old row value)
          if (c > 0) in |= dp[c - 1];                   // from left (already new row)
        }
        dp[c] = (grid[r][c] == '(') ? (in << 1) : (in >> 1);
      }
    }
    return dp[C - 1][0];
  }
};


int main() {
  vector<vector<char>> grid;
  cout << boolalpha;

  grid = { {'(', '(', '('}, {')', '(', ')'}, {'(', '(', ')'}, {'(', '(', ')'} }; RUN;
  grid = { {')', ')'}, {'(', '('} }; RUN;
  grid = { {'(',')',')','(','(','(','(',')',')','(',')','(',')','(','(','(','(',')','(',')','('},{'(','(',')',')','(',')',')',')','(',')','(',')','(','(',')','(','(','(','(','(',')'},{')',')','(',')',')','(','(',')','(','(',')','(',')',')','(',')',')','(','(',')',')'},{'(','(',')','(',')','(',')',')',')','(',')','(','(',')','(',')',')','(',')',')',')'},{'(','(','(',')','(','(',')','(',')',')','(',')',')',')',')',')',')','(',')','(','('},{')',')','(','(',')',')',')',')',')','(',')',')',')','(','(',')','(','(','(','(',')'},{')',')',')',')','(',')','(',')','(','(',')','(','(',')','(','(',')',')','(',')','('},{'(',')','(','(','(',')',')',')',')','(','(',')','(','(',')',')','(',')',')',')','('},{'(',')','(',')','(','(','(','(',')','(','(','(','(','(','(',')','(',')','(',')',')'},{'(',')','(','(','(',')','(',')',')',')',')','(','(','(','(',')',')','(','(','(',')'},{'(','(',')','(',')',')','(',')','(',')',')',')',')',')','(',')','(',')',')',')','('},{')','(','(','(',')','(',')',')','(',')','(',')','(','(',')','(','(',')','(','(',')'},{'(',')','(',')',')','(','(',')','(',')','(',')',')',')','(','(','(','(',')','(',')'},{'(','(',')','(',')',')','(','(','(',')','(',')','(','(',')',')','(','(','(',')',')'},{'(','(','(','(',')',')','(',')','(','(','(',')',')','(',')','(',')',')',')',')','('},{'(','(','(',')',')',')','(',')',')','(',')',')','(','(',')','(',')','(','(','(',')'},{')',')',')',')',')',')','(',')',')',')','(','(',')','(',')','(','(','(','(',')',')'} }; RUN;
  grid = { {'(',')','(','('},{'(',')',')','('},{')','(',')',')'},{')','(','(','('},{'(',')','(','('},{'(',')','(','('},{')',')','(',')'} }; RUN;
}
#endif
