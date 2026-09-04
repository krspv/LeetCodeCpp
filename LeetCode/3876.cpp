#ifdef TASK_3876
#include <ios>
#include <iostream>
#include <iterator>
#include <limits>
#include <memory>
#include <vector>
using namespace std;


class Solution {
private:
  enum Parity: short { None = 0, Even = 0b01, Odd = 0b10, Both = 0b11 };
public:
  bool uniformArray(vector<int>& nums1) {
    if (1 == size(nums1)) return true;

    int min_elem = numeric_limits<int>::max();
    Parity parity = Parity::None;
    for (int num : nums1) {
      parity = Parity(short(parity) | short((num % 2) ? Parity::Odd : Parity::Even));
      if (min_elem > num) min_elem = num;
    }

    if (min_elem % 2 == 0 && parity == Parity::Both) return false;
    return true;
  }
};


int main() {
  cout << boolalpha;
  cout << Solution().uniformArray(*make_unique<vector<int>>(vector{ 1, 4, 7 })) << endl;
  cout << Solution().uniformArray(*make_unique<vector<int>>(vector{ 2, 3 })) << endl;
  cout << Solution().uniformArray(*make_unique<vector<int>>(vector{ 4, 6 })) << endl;
}
#endif
