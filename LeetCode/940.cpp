#ifdef TASK_940
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
private:
  const int MOD = 1'000'000'007;
public:
  int distinctSubseqII(string s) {
    vector<int> prevs{ 0, 1 };
    int L = static_cast<int>(s.length());
    prevs.reserve(L + 1);
    for (int i = 1; i < L; ++i) {
      int k = i - 1;
      while (k >= 0 && s[k] != s[i]) --k;
      int prev = prevs.back();
      int next = ((prev << 1) - (k >= 0 ? prevs[k] : -1)) % MOD;
      if (next < 0) next += MOD;
      prevs.push_back(next);
    }
    return prevs.back();
  }
};


int main() {
  cout << Solution().distinctSubseqII("abc") << endl;
  cout << Solution().distinctSubseqII("aba") << endl;
  cout << Solution().distinctSubseqII("aaa") << endl;
  cout << Solution().distinctSubseqII("zchmliaqdgvwncfatcfivphddpzjkgyygueikthqzyeeiebczqbqhdytkoawkehkbizdmcnilcjjlpoeoqqoqpswtqdpvszfaksn") << endl;
}
#endif
