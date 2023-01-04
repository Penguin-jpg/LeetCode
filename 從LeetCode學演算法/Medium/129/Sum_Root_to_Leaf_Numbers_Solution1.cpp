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
            我的方法
            時間複雜度O(n)、空間複雜度O(logn)
            利用DFS走到底，再將數字加到總和
        */

        int sum = 0;
        return findSum(root, 0, sum);
    }

    int findSum(TreeNode *root, int current, int &sum)
    {
        current = current * 10 + root->val;

        if (root->left == NULL && root->right == NULL)
        {
            sum += current;
            return sum;
        }

        if (root->left != NULL)
        {
            findSum(root->left, current, sum);
        }

        if (root->right != NULL)
        {
            findSum(root->right, current, sum);
        }

        return sum;
    }
};