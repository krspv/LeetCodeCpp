#ifdef TASK_3871
#include <iostream>
using namespace std;


class Solution {
private:
  long long recursive(long long n, long long depth) {
    long long maxVal = 999;
    for (int i = 0; i < depth; ++i)
      maxVal = 1'000 * maxVal + 999;
    long long prevVal = maxVal / 1'000;
    return n <= maxVal ? (n - prevVal) * depth : (maxVal - prevVal) * depth + recursive(n, depth + 1);
  }
public:
  long long countCommas2(long long n) {
    long long total = 0;

    if (n <= 999) return 0;
    else return recursive(n, 1);

    return total;
  }

  long long countCommas(long long n) {
    long long total = 0;

    if (n > 999) {
      if (n <= 999'999LL)
        total += n - 999;
      else {
        total += 999'000;
        if (n <= 999'999'999LL)
          total += (n - 999'999LL) * 2;
        else {
          total += 999'000'000LL * 2;
          if (n <= 999'999'999'999LL)
            total += (n - 999'999'999LL) * 3;
          else {
            total += 999'000'000'000LL * 3;
            if (n <= 999'999'999'999'999LL)
              total += (n - 999'999'999'999LL) * 4;
            else {
              total += 999'000'000'000'000LL * 4;
              total += (n - 999'999'999'999'999) * 5;
            }
          }
        }
      }
    }

    return total;
  }
};


int main() {
  cout << Solution().countCommas(1002LL) << endl;
  cout << Solution().countCommas(998LL) << endl;
  cout << Solution().countCommas2(4156456998LL) << endl;
}
#endif
