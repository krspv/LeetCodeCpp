#ifdef TASK_3069
#include <iostream>
#include <vector>
#include <ranges>
using namespace std;


class Solution {
public:
  const vector<int> &resultArray(const vector<int>& nums) {
    vector<int> arr2;
    vecRet.reserve(nums.size());
    arr2.reserve(nums.size());
    vecRet.push_back(nums[0]);
    arr2.push_back(nums[1]);

    for (int num : nums | views::drop(2)) {
      if (vecRet.back() > arr2.back())
        vecRet.push_back(num);
      else
        arr2.push_back(num);
    }

    vecRet.insert(end(vecRet), cbegin(arr2), cend(arr2));
    return vecRet;
  }
private:
  vector<int> vecRet;
};


static void printVec(const vector<int>& vec) {
  for (int num : vec) {
    cout << num << ' ';
  }
  cout << endl;
}


int main() {
  printVec(Solution().resultArray(vector{ 2, 1, 3 }));
  printVec(Solution().resultArray(vector{ 5, 4, 3, 8 }));
}
#endif
