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
    void flatten(TreeNode* root) {
        /*
            參考的方法1
            時間複雜度O(n)、空間複雜度O(1)
            利用Morris Traversal的概念
        */

        if(root==NULL)
        {
            return;
        }
        
        TreeNode* leftNode=root->left;
        TreeNode* rightNode=root->right;
        flatten(root->left);
        flatten(root->right);
        
        root->left=NULL;
        root->right=leftNode;
        
        while(root->right!=NULL)
        {
            root=root->right;
        }
        
        root->right=rightNode;
    }
};