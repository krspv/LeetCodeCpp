#ifdef TASK_2058
#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    vector<int> vecRet{ -1, -1 };

    ListNode* pFirst = head;
    ListNode* pSecond = pFirst->next;
    int nCurPos = 0, nFirstPos = -1, nPrevPos = -1;

    while (pSecond->next != nullptr) {
      ListNode* pThird = pSecond->next;
      if ((pSecond->val > pFirst->val && pSecond->val > pThird->val) || (pSecond->val < pFirst->val && pSecond->val < pThird->val)) {
        if (nFirstPos == -1) nFirstPos = nCurPos;
        if (nPrevPos != -1) {
          int nDist = nCurPos - nPrevPos;
          if (vecRet[0] == -1 || vecRet[0] > nDist) vecRet[0] = nDist;
        }
        nPrevPos = nCurPos;
      }
      pFirst = pSecond;
      pSecond = pThird;
      ++nCurPos;
    }

    if (nFirstPos != -1 && nPrevPos != -1 && nFirstPos < nPrevPos) vecRet[1] = nPrevPos - nFirstPos;

    return vecRet;
  }
};

static ListNode *MakeList(const vector<int>& vec) {
  ListNode* pHead = new ListNode(vec[0]);
  ListNode* pCurrent = pHead;

  for (size_t i = 1; i < vec.size(); ++i) {
    pCurrent->next = new ListNode(vec[i]);
    pCurrent = pCurrent->next;
  }

  return pHead;
}

static void DestroyList(ListNode* pHead) {
  while (pHead != nullptr) {
    ListNode* pCurrent = pHead;
    pHead = pHead->next;
    delete pCurrent;
  }
}

static void printVec(const vector<int>& vec) {
  for (int num : vec) {
    cout << num << ' ';
  }
  cout << endl;
}

int main() {
  ListNode* pList = MakeList({ 3, 1 });
  printVec(Solution().nodesBetweenCriticalPoints(pList));
  DestroyList(pList);

  pList = MakeList({ 5, 3, 1, 2, 5, 1, 2 });
  printVec(Solution().nodesBetweenCriticalPoints(pList));
  DestroyList(pList);

  pList = MakeList({ 1, 3, 2, 2, 3, 2, 2, 2, 7 });
  printVec(Solution().nodesBetweenCriticalPoints(pList));
  DestroyList(pList);

  pList = MakeList({ 2, 2, 1, 3 });
  printVec(Solution().nodesBetweenCriticalPoints(pList));
  DestroyList(pList);
}
#endif
