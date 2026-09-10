#ifdef TASK_2265
using namespace std;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
private:
  struct Twosome {
    int total, sum;
    Twosome(int _total, int _sum) :total(_total), sum(_sum) {}
  };

  int count;

  Twosome recursive(TreeNode* root) {
    Twosome ret(1, root->val), left(0, 0), right(0, 0);

    if (root->left)
      left = recursive(root->left);
    if (root->right)
      right = recursive(root->right);

    ret.sum += left.sum + right.sum;
    ret.total += left.total + right.total;
    if (root->val == ret.sum / ret.total)
      ++count;

    return ret;
  }
public:
  int averageOfSubtree(TreeNode* root) {
    count = 0;
    recursive(root);
    return count;
  }
};


int main() {
}
#endif
