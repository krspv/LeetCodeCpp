#ifdef TASK_9
#include <iostream>
using namespace std;


class Solution {
public:
  bool isPalindrome(int x) {
    int arr[10], len = 0;
    if (x > -1) {
      do {
        arr[len++] = x % 10;
        x /= 10;
      } while (x > 0);
      for (int i = 0; i < len / 2; ++i)
        if (arr[i] != arr[len - i - 1])
          return false;
      return true;
    }
    return false;
  }
};


int main() {
  cout << boolalpha;
  cout << Solution().isPalindrome(0) << endl;
  cout << Solution().isPalindrome(121) << endl;
  cout << Solution().isPalindrome(-121) << endl;
}
#endif
