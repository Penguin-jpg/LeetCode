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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        /*
            我的方法1
            worst case:時間複雜度O(n)
            average case:時間複雜度O(log(N))
            空間複雜度O(log(N))
            遞迴
        */

        if(root==NULL)
        {
            return new TreeNode(val);
        }
        
        if(val<root->val)
        {
            root->left=insertIntoBST(root->left,val);
        }else
        {
            root->right=insertIntoBST(root->right,val);
        }
        
        return root;
    }
};