/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        /*
            參考的方法
            時間複雜度O(n)、空間複雜度O(logn)
            利用DFS走到底，再將數字加到總和
        */

        return findSum(root, 0);
    }

    int findSum(TreeNode *root, int current)
    {
        if (root == NULL)
        {
            return 0;
        }

        current = current * 10 + root->val;

        if (root->left == NULL && root->right == NULL)
        {
            return current;
        }

        return findSum(root->left, current) + findSum(root->right, current);
    }
};