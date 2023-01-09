#include <vector>
using namespace std;

/**
 * 參考想法: 對稱就是 root->left->val == root->right->val -> 檢查所有的 pair，若都相同即為對稱
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
    bool isSymmetric(TreeNode *root)
    {
        return checkSymmetric(root->left, root->right);
    }

    bool checkSymmetric(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr && root2 == nullptr)
        {
            return true;
        }
        else if (root1 == nullptr || root2 == nullptr)
        {
            return false;
        }
        else if (root1->val != root2->val)
        {
            return false;
        }
        return checkSymmetric(root1->left, root2->right) && checkSymmetric(root1->right, root2->left);
    }
};