/**
 * 想法: 觀察可看出能分為兩種情況：
 *      1. p,q 在同一子樹 -> p 是 LCA 或 q 是 LCA
 *      2. p,q 在不同子樹 -> root 是 LCA
 * (失敗，雖然想法沒錯，但有點想不到該怎麼更好的實作出來)
 * 時間: O(n), 空間: O(logn)
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {
    }
};

class Solution
{
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (isAncestor(p, q))
        {
            return p;
        }
        else if (isAncestor(q, p))
        {
            return q;
        }
        return root;
    }

    bool isAncestor(TreeNode *root, TreeNode *node)
    {
        if (root == nullptr)
        {
            return false;
        }
        else if (root == node)
        {
            return true;
        }
        return isAncestor(root->left, node) || isAncestor(root->right, node);
    }
};