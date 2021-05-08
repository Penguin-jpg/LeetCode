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
    int minDepth(TreeNode* root) {
        /*
            參考的方法1
            時間複雜度O(n)、空間複雜度O(n)
            算出每條路徑長度，找最短的
        */

        if(root==NULL)
        {
            return 0;
        }
        
        int height=INT_MAX;
        
        if(root->left!=NULL)
        {
            height=minDepth(root->left);
        }
        
        if(root->right!=NULL)
        {
            height=min(height,minDepth(root->right));
        }
        
        return height==INT_MAX?1:height+1;
    }
};