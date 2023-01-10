#include <queue>

/**
 * 想法: 透過 level order 的走訪找到最大深度
 * 時間: O(n), 空間: O(h)
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
        : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) TreeNode()
        : val(x),
          left(nullptr),
          right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){} *
};

class Solution
{
  public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        queue<TreeNode *> nodes;
        int level = 0;
        nodes.push(root);
        int size = nodes.size();
        while (!nodes.empty())
        {
            for (int i = 0; i < size; i++)
            {
                TreeNode *current = nodes.front();
                nodes.pop();
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
            level++;
        }
        return level;
    }
};