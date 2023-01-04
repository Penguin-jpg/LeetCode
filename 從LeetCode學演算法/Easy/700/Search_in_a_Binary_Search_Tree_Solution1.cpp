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
    TreeNode* searchBST(TreeNode* root, int val) {   
        /*
            我的方法(大部分的人都是這樣寫)
            worst case:時間複雜度O(n) (整棵樹都是斜的)
            average case:時間複雜度O(log(N))
            空間複雜度O(1)
        */

        if(root==NULL)
        {
            return NULL;
        }
        
        if(root->val==val)
        {
            return root;
        }else if(val<root->val)
        {
            return searchBST(root->left,val);
        }else
        {
            return searchBST(root->right,val);
        }
    }
};