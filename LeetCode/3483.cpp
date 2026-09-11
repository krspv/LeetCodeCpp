#ifdef TASK_3483
#include <iostream>
#include <memory>
#include <vector>
using namespace std;


class Solution {
public:
  int totalNumbers(vector<int>& digits) {
    vector<bool> used(1000);
    int count = 0;
    
    bool bHasEven = false;
    for (int digit : digits) {
      if (digit % 2 == 0) {
        bHasEven = true;
        break;
      }
    }

    if (!bHasEven) return 0;

    for (size_t i = 0; i < size(digits); ++i)
      if (digits[i] != 0)
        for (size_t j = 0; j < size(digits); ++j)
          if (i != j)
            for (size_t k = 0; k < size(digits); ++k)
              if (k != i && k != j && (digits[k] % 2 == 0)) {
                int num = 100 * digits[i] + 10 * digits[j] + digits[k];
                if (!used[num]) {
                  used[num] = true;
                  ++count;
                }
              }
    return count;
  }
};


int main() {
  cout << Solution().totalNumbers(*make_unique<vector<int>>(vector{ 1, 2, 3, 4 })) << endl;
  cout << Solution().totalNumbers(*make_unique<vector<int>>(vector{ 0, 2, 2 })) << endl;
  cout << Solution().totalNumbers(*make_unique<vector<int>>(vector{ 6, 6, 6 })) << endl;
  cout << Solution().totalNumbers(*make_unique<vector<int>>(vector{ 1, 1, 1, 1, 5 })) << endl;
}
#endif
