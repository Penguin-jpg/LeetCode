/**
 * 參考解答: 漂亮版的解法1
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
        : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) TreeNode()
        : val(x),
          left(nullptr),
          right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){} *
};

class Solution
{
  public:
    int maxDepth(TreeNode *root)
    {
        return root == nullptr ? 0 : max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
};