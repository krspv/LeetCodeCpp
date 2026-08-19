#ifdef TASK_1386
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
  int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    int nMaxRow = (*max_element(begin(reservedSeats), end(reservedSeats), [](const std::vector<int>& a, const std::vector<int>& b) { return a[0] < b[0]; }))[0];
    vector<short> rows(nMaxRow);

    for (const auto& seat : reservedSeats) {
      rows[seat[0] - 1] |= 1 << (seat[1] - 1);
    }

    int count = 0;
    for (int row : rows) {
      if (((row ^ r2X) & r2X) == r2X) count += 2;
      else if (((row ^ r2345) & r2345) == r2345) ++count;
      else if (((row ^ r4567) & r4567) == r4567) ++count;
      else if (((row ^ r6789) & r6789) == r6789) ++count;
    }

    return count + 2*(n - nMaxRow);
  }
private:
  const int r2345 = 30, r4567 = 120, r6789 = 480, r2X = 510;
};


int main() {
  cout << Solution().maxNumberOfFamilies(3, *make_unique<vector<vector<int>>>(vector{ vector{1, 2}, vector{1, 3}, vector{1, 8}, vector{2, 6}, vector{3, 1}, vector{3, 10} })) << endl;
  cout << Solution().maxNumberOfFamilies(2, *make_unique<vector<vector<int>>>(vector{ vector{2, 1}, vector{1, 8}, vector{2, 6} })) << endl;
  cout << Solution().maxNumberOfFamilies(4, *make_unique<vector<vector<int>>>(vector{ vector{4, 3}, vector{1, 4}, vector{4, 6}, vector{1, 7} })) << endl;
  cout << Solution().maxNumberOfFamilies(10, *make_unique<vector<vector<int>>>(vector{ vector{2, 1}, vector{1, 8}, vector{2, 6} })) << endl;
}
#endif
