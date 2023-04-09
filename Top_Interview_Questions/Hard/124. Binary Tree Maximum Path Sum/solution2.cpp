#include <algorithm>
using namespace std;

/**
 * 想法: 稍微修改 solution1 的 function 名稱，讓整體更直覺
 * 時間: O(n), 空間: O(h), h: 樹高
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
    int maxPathSum(TreeNode *root)
    {
        int maxSum = INT_MIN;
        gainFromSubtree(root, maxSum);
        return maxSum;
    }

    // the "gain" we can get from a subtree
    int gainFromSubtree(TreeNode *root, int &maxSum)
    {
        if (root == nullptr)
        {
            return 0; // null contributes 0 gain
        }
        // if gain from left subtree is negative, then we don't need it
        int gainFromLeftSubtree = std::max(gainFromSubtree(root->left, maxSum), 0);
        // same thing goes for right subtree
        int gainFromRightSubtree = std::max(gainFromSubtree(root->right, maxSum), 0);
        // check if select both subtrees is bigger than current max sum
        maxSum = std::max(maxSum, root->val + gainFromLeftSubtree + gainFromRightSubtree);
        // gain: root->val + max(gain from left subtree, gain from right subtree)
        return root->val + std::max(gainFromLeftSubtree, gainFromRightSubtree);
    }
};