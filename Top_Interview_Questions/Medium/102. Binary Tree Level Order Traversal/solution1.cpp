#include <queue>
#include <vector>
using namespace std;

/**
 * 想法: 按照題目要求做 level order traversal，也就是 BFS
 * 時間: O(n), 空間: O(2^logn)
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        vector<vector<int>> results;
        queue<TreeNode *> nodes;
        nodes.push(root);
        int size = nodes.size();
        TreeNode *current = nullptr;
        while (!nodes.empty())
        {
            vector<int> values;
            for (int i = 0; i < size; i++)
            {
                current = nodes.front();
                nodes.pop();
                values.push_back(current->val);
                if (current->left != nullptr)
                {
                    nodes.push(current->left);
                }
                if (current->right != nullptr)
                {
                    nodes.push(current->right);
                }
            }
            size = nodes.size();
            results.push_back(values);
        }
        return results;
    }
};