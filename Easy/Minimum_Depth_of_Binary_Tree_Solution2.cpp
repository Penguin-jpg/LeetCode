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
            參考的方法2
            時間複雜度O(n)、空間複雜度O(n)
            比較每條路徑的長度，找出最短的
        */

        if(root==NULL)
        {
            return 0;
        }else
        {
            return min(minDepth(root->left),minDepth(root->right))+1;
        }
    }
    
    int min(int a,int b)
    {
        if(a==0)//root==NULL
        {
            return b;
        }
        
        if(b==0)//root==NULL

        {
            return a;
        }
        
        return a<b?a:b;
    }
};