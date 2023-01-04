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
            參考的方法3
            時間複雜度O(n)、空間複雜度O(n)
            算出每條路徑長度，找最短的
        */

        if(root==NULL)
        {
            return 0;
        }
        
        int left=minDepth(root->left);
        int right=minDepth(root->right);
        
        if(left==0||right==0)
        {
            return left+right+1;
        }else
        {
            return min(left,right)+1;
        }
    }
};