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
            參考的方法1
            時間複雜度O(log(n))、空間複雜度O(log(n))
            分為三種情況:
            1. root的值不介於p的值和q的值之間，代表p、q個別在左右子樹，LCA為root
            2. p的值小於root的值且q的值小於root的值，代表LCA在左子樹，所以繼續往左子樹找
            3. p的值大於root的值且q的值大於root的值，代表LCA在右子樹，所以繼續往右子樹找
        */

        if(p->val<root->val&&q->val<root->val) //在左子樹
        {
            return lowestCommonAncestor(root->left,p,q);
        }else if(p->val>root->val&&q->val>root->val) //在右子樹
        {
            return lowestCommonAncestor(root->right,p,q); 
        }else //如果p、q分別在左右子樹，則LCA為root
        {  
            return root;
        }  
    }
};