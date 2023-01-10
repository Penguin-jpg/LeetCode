/**
 * 想法: 由於左右同時走會導致不確定哪邊比較深，所以每次都分別拆成往左走及往右走，各自計算深度，再取最大的值
 * 時間: O(n), 空間: O(h), h: 最大深度
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
        return getDepth(root, 0);
    }

    int getDepth(TreeNode *root, int level)
    {
        if (root == nullptr)
        {
            return level;
        }
        int leftDepth = getDepth(root->left, level + 1);
        int rightDepth = getDepth(root->right, level + 1);
        return leftDepth > rightDepth ? leftDepth : rightDepth;
    }
};