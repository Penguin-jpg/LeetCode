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
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        /*
            參考的方法
            時間複雜度O(n)、空間複雜度O(log(n))
            利用DFS，但是做法和我的不同，如果遇到NULL就回傳NULL，否則就交換左右子樹
            (會由前面的節點開始反轉，最後才做後面的節點)
        */

        if(root==NULL)
        {
            return root;
        }
        
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};