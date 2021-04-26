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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        /*
            參考的方法1
            時間複雜度:O(n)
            空間複雜度:O(logN) (每層的節點數量會是1,2,4,8,16,...，總和N=2^(n-1)，n為層數)
            檢查root是否相等、左子樹是否相等、右子樹是否相等，如果都相等就回傳true，否則就回傳false
        */

        if(p==NULL&&q==NULL)
        {
            return true;
        }else if(p==NULL||q==NULL)
        {
            return false;
        }else
        {
            return (p->val==q->val)&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        }
    }
};