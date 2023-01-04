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
    bool isSymmetric(TreeNode* root) {
        /*
            參考50%+自己想50%的方法
            複雜度O(n)，左子樹的左節點要等於右子樹的右節點；左子樹的右節點要等於右子樹的左節點
        */

        //根節點為NULL時一定為true
        if(root==NULL)
        {
            return true;
        }
        
        return isSymmetric(root->left,root->right);
    }
    
    bool isSymmetric(TreeNode* l,TreeNode* r)
    {
        //兩者都為NULL也算相等
        if(l==NULL&&r==NULL)
        {
            return true;
        }else if(l==NULL||r==NULL) //只有一個為NULL不算相等
        {
            return false;
        }else if(l->val==r->val) //值相同時就繼續往下找
        {
            return isSymmetric(l->left,r->right)&&isSymmetric(l->right,r->left);
        }else
        {
            return false;
        }
    }
};