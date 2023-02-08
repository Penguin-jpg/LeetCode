#include <vector>
using namespace std;

/**
 * 想法: BST 透過 inorder traversal 應該會是由小到大排序，若不是，則代表有問題
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
    bool isValidBST(TreeNode *root)
    {
        vector<int> nums;
        inorder(root, nums);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] <= nums[i - 1])
            {
                return false;
            }
        }
        return true;
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