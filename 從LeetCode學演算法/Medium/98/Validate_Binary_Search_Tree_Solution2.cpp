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
    TreeNode* compare;
    bool isValidBST(TreeNode* root) {
        /*
            參考的方法2
            時間複雜度O(n)、空間複雜度O(1)
            加入最大值與最小值的檢查，相當於解法1和紀錄的節點做比較，
            但這個方法更直觀
        */

        return isValid(root,LONG_MAX,LONG_MIN);
    }
    
    bool isValid(TreeNode* root,long max,long min)
    {
        if(root==NULL)
        {
            return true;
        }
        
        //檢查左子樹是否符合定義
        bool left=isValid(root->left,root->val,min);
        //檢查右子樹是否符合定義
        bool right=isValid(root->right,max,root->val);
        
        //root本身也要符合定義
        if(root->val>min&&root->val<max&&left&&right)
        {
            return true;
        }else
        {
            return false;
        }
    }
};