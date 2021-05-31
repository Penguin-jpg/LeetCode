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
    TreeNode* insertIntoBST(TreeNode* root, int val) {   
        /*
            我的方法2
            worst case:時間複雜度O(n)
            average case:時間複雜度O(log(N))
            空間複雜度O(1)
            Iterative
        */

        TreeNode* current=root;
        TreeNode* parent=NULL;
        
        while(current!=NULL)
        {
            parent=current;
            
            if(val<current->val)
            {
                current=current->left;
            }else
            {
                current=current->right;   
            }
        }
        
        if(parent==NULL)
        {
            return new TreeNode(val);
        }else if(val<parent->val)
        {
            parent->left=new TreeNode(val);
        }else
        {
            parent->right=new TreeNode(val);
        }
        
        return root;
    }
};