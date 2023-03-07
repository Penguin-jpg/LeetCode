#include <stack>
using namespace std;

/**
 * 參考解答: 用 iterative 的方式做
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
        stack<TreeNode *> nodes;
        TreeNode *current = root;
        while (!nodes.empty() || current != nullptr)
        {
            if (current != nullptr)
            {
                nodes.push(current); // imagine pushing root to stack just like recursion
                current = current->left;
            }
            else
            {
                // imagine end of recursion and back to last step, so this is the middle node
                TreeNode *node = nodes.top();
                nodes.pop();
                k--;
                if (k == 0)
                {
                    return node->val;
                }
                current = node->right; // start from right
            }
        }
        return -1;
    }
};