/**
 * 想法: 觀察後可發現，當走到底回來之後的第 k 個就是答案，可以透過一個 counter
 * 紀錄目前是往回走的第幾個，並在第 k 個的時候直接記錄答案回傳
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
        inorder(root, counter, k, result);
        return result;
    }

    void inorder(TreeNode *root, int &counter, int k, int &result)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left, counter, k, result);
        counter++;
        if (counter == k)
        {
            result = root->val;
            return;
        }
        inorder(root->right, counter, k, result);
    }
};