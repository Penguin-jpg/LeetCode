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
    vector<int> nodes;

    vector<int> inorderTraversal(TreeNode* root) {
        /*
            我的方法1
            時間複雜度O(n)、空間複雜度O(number of nodes + height of tree)
            遞迴
        */

        if(root==NULL)
        {
            return nodes;
        }else
        {
            inorderTraversal(root->left);
            nodes.push_back(root->val);
            inorderTraversal(root->right);
        }
        
        return nodes;
    }
};