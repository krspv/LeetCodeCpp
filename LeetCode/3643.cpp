#ifdef TASK_3643
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Solution {
public:
  const vector<vector<int>> &reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
    for (int row = x; row < x + (k >> 1); ++row) {
      auto& v1 = grid[row];
      auto& v2 = grid[2*x + k - 1 - row];
      for (int col = y; col < y + k; ++col)
        swap(v1[col], v2[col]);
    }
    return grid;
  }
};


static void printVec(vector<vector<int>> grid) {
  for (auto vec : grid) {
    for (int i : vec)
      cout << setw(2) << i << ' ';
    cout << endl;
  }
  cout << endl;
}


int main() {
  printVec(Solution().reverseSubmatrix(*make_unique<vector<vector<int>>>(vector{ vector{1, 2, 3, 4}, vector{5, 6, 7, 8}, vector{9, 10, 11, 12}, vector{13, 14, 15, 16} }), 1, 0, 3));
  printVec(Solution().reverseSubmatrix(*make_unique<vector<vector<int>>>(vector{ vector{3, 4, 2, 3}, vector{2, 3, 4, 2} }), 0, 2, 2));
  printVec(Solution().reverseSubmatrix(*make_unique<vector<vector<int>>>(vector<vector<int>>{ vector{ 1, 2, 3, 4, 5, 6 } }), 0, 2, 1));
  printVec(Solution().reverseSubmatrix(*make_unique<vector<vector<int>>>(vector<vector<int>>{ vector{ 1, 2, 3, 4, 5, 6 } }), 0, 2, 0));
  printVec(Solution().reverseSubmatrix(*make_unique<vector<vector<int>>>(vector{ vector{1}, vector{2}, vector{3}, vector{4}, vector{5}, vector{6} }), 2, 0, 1));
}
#endif
