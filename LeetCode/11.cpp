#ifdef TASK_11
#include <iostream>
#include <memory>
#include <vector>
using namespace std;


class Solution {
public:
  int maxArea(vector<int>& height) {
    int a(0), b(static_cast<int>(height.size() - 1));
    int maxWater = 0;
    while (a != b) {
      int ha(height[a]), hb(height[b]);
      if (ha && hb) {
        int calc = (b - a) * (ha < hb ? ha : hb);
        if (maxWater < calc) maxWater = calc;
      }
      if (ha < hb) ++a;
      else --b;
    }
    return maxWater;
  }
};


int main() {
  cout << Solution().maxArea(*make_unique<vector<int>>(vector{ 1, 8, 6, 2, 5, 4, 8, 3, 7 })) << endl;
  cout << Solution().maxArea(*make_unique<vector<int>>(vector{ 1, 1 })) << endl;
}
#endif
