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
    bool result=true;
    bool isBalanced(TreeNode* root) {
        /*
            參考的方法1
            時間複雜度O(n)、空間複雜度O(n)
            透過一個bool檢查，當result為false時(發現一組的左右子樹高度差>1)，
            就不需要再做maxDepth了，可以省下很多時間
        */

        maxHeight(root);
        return result;
    }
    
    int maxHeight(TreeNode* root)
    {
        if(root==NULL||!result)
        {
            return 0;
        }
        
        int left=maxHeight(root->left);
        int right=maxHeight(root->right);
        
        if(abs(left-right)>1)
        {
            result=false;
            return 0;
        }
        
        return max(left,right)+1;
    }
};