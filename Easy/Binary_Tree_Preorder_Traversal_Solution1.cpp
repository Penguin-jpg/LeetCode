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
    vector<int> preorderTraversal(TreeNode* root) {
        /*
            我的方法1
            時間複雜度O(n)、空間複雜度O(n)
            遞迴
        */

        vector<int> nums;
        preorder(nums,root);
        return nums;
    }
    
    void preorder(vector<int>& nums,TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        
        nums.push_back(root->val);
        preorder(nums,root->left);
        preorder(nums,root->right);
    }
};