#ifdef TASK_1621
#include <iostream>
using namespace std;


class Solution {
private:
  const int MOD = 1'000'000'007;
  long long modinv(long long x) { return power(x, MOD - 2, MOD); }
  long long power(long long base, long long exp, long long mod) {
    base %= mod;
    long long res = 1;
    while (exp > 0) {
      if (exp & 1) res = res * base % mod;
      base = base * base % mod;
      exp >>= 1;
    }
    return res;
  }
public:
  int numberOfSets(int n, int k) {
    int nMaxLineSegments = n - 1;

    if (nMaxLineSegments < k) return 0;
    if (nMaxLineSegments == k) return 1;
    if (k == 1) return n * (n - 1) / 2;

    long long num = 1, den = 1;
    for (int u = 2*k + 1, d = 1; d < n - k; ++u, ++d) {
      num = (num * u) % MOD;
      den = (den * d) % MOD;
    }

    return static_cast<int>(num * modinv(den) % MOD);
  }
};


int main() {
  cout << Solution().numberOfSets(2, 1) << endl;
  cout << "-------------\n";
  cout << Solution().numberOfSets(3, 1) << endl;
  cout << Solution().numberOfSets(3, 2) << endl;
  cout << "-------------\n";
  cout << Solution().numberOfSets(4, 1) << endl;
  cout << Solution().numberOfSets(4, 2) << endl;
  cout << Solution().numberOfSets(4, 3) << endl;
  cout << "-------------\n";
  cout << Solution().numberOfSets(5, 1) << endl;
  cout << Solution().numberOfSets(5, 2) << endl;
  cout << Solution().numberOfSets(5, 3) << endl;
  cout << Solution().numberOfSets(5, 4) << endl;
  cout << "-------------\n";
  cout << Solution().numberOfSets(6, 1) << endl;
  cout << Solution().numberOfSets(6, 2) << endl;
  cout << Solution().numberOfSets(6, 3) << endl;
  cout << Solution().numberOfSets(6, 4) << endl;
  cout << Solution().numberOfSets(6, 5) << endl;
  cout << "-------------\n";
  cout << Solution().numberOfSets(7, 1) << endl;
  cout << Solution().numberOfSets(7, 2) << endl;
  cout << Solution().numberOfSets(7, 3) << endl;
  cout << Solution().numberOfSets(7, 4) << endl;
  cout << Solution().numberOfSets(7, 5) << endl;
  cout << Solution().numberOfSets(7, 6) << endl;
  cout << "-------------\n";
  cout << Solution().numberOfSets(30, 7) << endl;
  cout << Solution().numberOfSets(897, 217) << endl;
}
#endif
