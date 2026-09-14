#ifdef TASK_836
#include <ios>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;


class Solution {
public:
  bool isRectangleOverlap(const vector<int>& rec1, const vector<int>& rec2) {
    return not (rec1[2] <= rec2[0] or rec2[2] <= rec1[0] or rec1[3] <= rec2[1] or rec2[3] <= rec1[1]);
  }
};


int main() {
  cout << boolalpha;
  cout << Solution().isRectangleOverlap(*make_unique<vector<int>>(vector{ 0, 0, 2, 2 }), *make_unique<vector<int>>(vector{ 1, 1, 3, 3 })) << endl;
  cout << Solution().isRectangleOverlap(*make_unique<vector<int>>(vector{ 0, 0, 1, 1 }), *make_unique<vector<int>>(vector{ 1, 0, 2, 1 })) << endl;
  cout << Solution().isRectangleOverlap(*make_unique<vector<int>>(vector{ 0, 0, 1, 1 }), *make_unique<vector<int>>(vector{ 2, 2, 3, 3 })) << endl;
  cout << Solution().isRectangleOverlap(*make_unique<vector<int>>(vector{ 7, 8, 13, 15 }), *make_unique<vector<int>>(vector{ 10, 8, 12, 20 })) << endl;
  cout << Solution().isRectangleOverlap(*make_unique<vector<int>>(vector{ 4, 4, 14, 7 }), *make_unique<vector<int>>(vector{ 4, 3, 8, 8 })) << endl;
}
#endif
