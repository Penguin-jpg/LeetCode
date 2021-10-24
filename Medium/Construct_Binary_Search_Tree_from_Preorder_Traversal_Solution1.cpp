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
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        /*
            參考的方法
            時間複雜度O(n)(n:陣列大小)、空間複雜度O(logn)
            先一路往左邊，如果目前的數比邊界值還大，就代表要回傳NULL，
            並檢查是否要接在右邊
        */

        int i = 0;
        TreeNode *root = buildTree(preorder, i, INT_MAX);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, int &i, int bound)
    {
        if (i == preorder.size() || preorder[i] > bound)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[i]);
        i++;

        root->left = buildTree(preorder, i, root->val);
        root->right = buildTree(preorder, i, bound);

        return root;
    }
};