#ifdef TASK_1401
#include <algorithm>
#include <ios>
#include <iostream>
using namespace std;


class Solution {
public:
  bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
    int dx = xCenter - clamp(xCenter, x1, x2);
    int dy = yCenter - clamp(yCenter, y1, y2);
    return dx * dx + dy * dy <= radius * radius;
  }
};


int main() {
  cout << boolalpha;
  cout << Solution().checkOverlap(1, 0, 0, 1, -1, 3, 1) << endl;
  cout << Solution().checkOverlap(1, 1, 1, 1, -3, 2, -1) << endl;
  cout << Solution().checkOverlap(1, 0, 0, -1, 0, 0, 1) << endl;
}
#endif
