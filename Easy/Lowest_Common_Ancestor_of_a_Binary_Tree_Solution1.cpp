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
            參考的方法
            時間複雜度O(n)、空間複雜度O(log(n))
            分成3種情況:
            1. p、q分別在左右子樹，則LCA為root
            2. p、q都在左子樹，則LCA在左子樹(p或q其中一個)
            3. p、q都在右子樹，則LCA在右子樹(p或q其中一個)
        */

        if(root==NULL)
        {
            return root;
        }else if(root==p||root==q)
        {
            return root;
        }
        
        TreeNode* leftNode=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightNode=lowestCommonAncestor(root->right,p,q);
        
        if(leftNode!=NULL&&rightNode!=NULL) //p、q分別在左右子樹
        {
            return root;
        }else if(leftNode!=NULL) //p、q都在左子樹
        {
            return leftNode;
        }else if(rightNode!=NULL) //p、q都在右子樹
        {
            return rightNode;
        }else //沒有LCA
        {
            return NULL;
        }
    }
};