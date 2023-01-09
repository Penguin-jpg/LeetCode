#include <vector>
using namespace std;

/**
 * 想法: inorder 是按照左中右的順序走訪 binary tree，按照規則遞迴完成即可
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> results;
        inorder(root, results);
        return results;
    }

    void inorder(TreeNode *root, vector<int> &results)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left, results);
        results.push_back(root->val);
        inorder(root->right, results);
    }
};