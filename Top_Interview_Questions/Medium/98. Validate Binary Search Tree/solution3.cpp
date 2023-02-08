/**
 * 參考解答: 用 inorder 的概念，目前 traversal 到的值要比之前的還小(一樣記得走
 * 到底在更新比較的值)
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
    bool isValidBST(TreeNode *root)
    {
        TreeNode *previous = nullptr;
        return isValid(root, previous);
    }

    bool isValid(TreeNode *root, TreeNode *&previous) // use reference to keep the latest value
    {
        if (root == nullptr)
        {
            return true;
        }
        if (!isValid(root->left, previous)) // left subtree
        {
            return false;
        }
        if (previous != nullptr && previous->val >= root->val) // check if value is less or equal to previous value
        {
            return false;
        }
        previous = root;                       // finally update the previous node
        return isValid(root->right, previous); // now for right subtree
    }
};