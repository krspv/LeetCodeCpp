#ifdef TASK_1807
#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>
#include <vector>
using namespace std;

#define RUN cout << Solution().evaluate(s, knowledge) << endl


class Solution {
public:
  string evaluate(const string &s, vector<vector<string>>& knowledge) {
    unordered_map<string, string> knw_map;
    knw_map.reserve(knowledge.size());
    for (const auto& kv : knowledge)
      knw_map.emplace(kv[0], kv[1]);

    string strRet;
    strRet.reserve(static_cast<size_t>(s.size() * 1.5));
    bool bInBracket = false;
    string key;
    for (char ch : s) {
      switch (ch) {
      case '(':
        bInBracket = true;
        key.clear();
        break;
      case ')':
        bInBracket = false;
        {
          auto it = knw_map.find(key);
          strRet += it != knw_map.end() ? it->second : "?";
        }
        break;
      default:
        if (bInBracket)
          key.push_back(ch);
        else
          strRet.push_back(ch);
      }
    }

    return strRet;
  }
};


int main() {
  string s;
  vector<vector<string>> knowledge;

  s = "(name)is(age)yearsold";  knowledge = { {"name", "bob"}, {"age", "two"} };  RUN;
  s = "hi(name)";               knowledge = { {"a", "b"} };                       RUN;
  s = "(a)(a)(a)aaa";           knowledge = { {"a", "yes"} };                     RUN;
}
#endif
