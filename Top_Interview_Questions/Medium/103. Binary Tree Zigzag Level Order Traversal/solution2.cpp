#include <queue>
#include <vector>
using namespace std;

/**
 * 參考解答: level order traversal 做法不需改變，只要記得在從右到左的情況下，必
 * 須將值從後往前存
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        vector<vector<int>> results;
        queue<TreeNode *> nodes;
        nodes.push(root);
        int size = nodes.size();
        bool fromLeft = true; // start from left
        TreeNode *current = nullptr;
        while (!nodes.empty())
        {
            vector<int> values(size);
            for (int i = 0; i < size; i++)
            {

                current = nodes.front();
                nodes.pop();
                int index = fromLeft ? i : size - i - 1; // if from right, then store from back to front
                values[index] = current->val;
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
            fromLeft = !fromLeft; // change direction
        }
        return results;
    }
};