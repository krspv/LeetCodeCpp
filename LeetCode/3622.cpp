#ifdef TASK_3622
#include <iostream>
using namespace std;


class Solution {
public:
  bool checkDivisibility(int n) {
    int sum = 0, prod = 1, tmp = n;
    do {
      int digit = tmp % 10;
      sum += digit;
      prod *= digit;
      tmp /= 10;
    } while (tmp > 0);
    return n % (sum + prod) == 0;
  }
};


int main() {
  cout << boolalpha;
  cout << Solution().checkDivisibility(99) << endl;
  cout << Solution().checkDivisibility(23) << endl;
}
#endif
