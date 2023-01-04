/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
            參考的方法2
            時間複雜度O(log(n))、空間複雜度O(1)
            將遞迴的方式改成迭代
        */

        while(root!=p&&root!=q)
        {
            if(p->val<root->val&&q->val<root->val)
            {
                root=root->left;
            }else if(p->val>root->val&&q->val>root->val)
            {
                root=root->right;
            }else
            {
                return root;
            }
        }
        
        return root;
    }
};