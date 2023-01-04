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
    int sum=0;
    int maxPathSum(TreeNode* root) {
        /*
            參考的方法
            時間複雜度O(n)、空間複雜度O(height of tree)
            將當前節點看成中繼點的話，會有四種情況:
            1. root->val  2. root->val+root->left->val  
            3. root->val+root-right->val  4. root->val+root->left->val+root->right->val
            只經過當前節點的話，只有三種情況:
            1. root->val  2. root->val+root->left->val  3. root->val+root->left->val+root->right->val
            比較各情況後，找出最大值，並更新目前最大值
        */

        sum=root->val;
        DFS(root);
        return sum;
    }
    
    int DFS(TreeNode* root)
    {
        int l=root->left!=NULL?DFS(root->left):0; //左邊節點的值
        int r=root->right!=NULL?DFS(root->right):0; //右邊節點的值
        int m=root->val; //本身的值
        
        //只經過該節點的情況
        //比較root->val+root->left->val和root->val+root->right->val
        if(l>r)
        {
            m=max(m,m+l);
        }else
        {
            m=max(m,m+r);
        }
        
        //將該節點當作中繼點的情況
        //比較上述兩項情況和root->val+root->left->val+root->right->val
        if(m>l+r+root->val)
        {
            sum=max(sum,m);
        }else
        {
            sum=max(sum,l+r+root->val);
        }
        
        return m;
    }
};