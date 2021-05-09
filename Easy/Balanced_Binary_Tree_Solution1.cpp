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
    bool isBalanced(TreeNode* root) {
        /*
            我的方法
            時間複雜度O(n)
            檢查每個節點的左右子樹高度差，左子樹和右子樹高度最多只能相差1
        */

        if(root==NULL)
        {
            return true;
        }else
        {
            if(abs(maxHeight(root->left)-maxHeight(root->right))>1)
            {
                return false;
            }else
            {
                return isBalanced(root->left)&&isBalanced(root->right);
            }
        }
    }
    
    //找高度
    int maxHeight(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }else
        {
            return max(maxHeight(root->left),maxHeight(root->right))+1;
        }
    }
};