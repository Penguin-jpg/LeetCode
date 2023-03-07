/**
 * 參考解答: solution2 的優化版，直接用 k 當 counter，每次做完就將 k 減 1，當 k==0 的時候就是要回傳了
 * 時間: O(k), 空間: O(logn)
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
    int kthSmallest(TreeNode *root, int k)
    {
        int counter = 0, result = 0;
        inorder(root, k, result);
        return result;
    }

    void inorder(TreeNode *root, int &k, int &result)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left, k, result);
        k--;
        if (k == 0)
        {
            result = root->val;
            return;
        }
        inorder(root->right, k, result);
    }
};