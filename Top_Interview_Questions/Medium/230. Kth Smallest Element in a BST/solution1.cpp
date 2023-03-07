#include <vector>
using namespace std;

/**
 * 想法: 由於給定 BST，只要用 inorder 走過一次就可以得到由小到大排序後的結果，
 * 在回傳第 k-1 個元素即可
 * 時間: O(n), 空間: O(n)
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
        vector<int> nums;
        inorder(root, nums);
        return nums[k - 1];
    }

    void inorder(TreeNode *root, vector<int> &nums)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
};