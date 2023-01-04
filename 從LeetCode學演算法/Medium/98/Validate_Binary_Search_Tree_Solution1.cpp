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
    TreeNode* compare; //比較用的節點
    bool isValidBST(TreeNode* root) {
        /*
            參考的方法1:
            時間複雜度O(n)、空間複雜度O(1)
            利用in-order的方式尋訪BST，可以得到由小到大排序的數列，先往左走到底，
            過程有不符合定義的就回傳false，否則就跟上一個紀錄的節點進行比較，
            如果目前的節點<=上一個紀錄的節點，就回傳false(因為越後面節點要越大)
        */

        if(root==NULL)
        {
            return true;
        }else if(!isValidBST(root->left))//往左走，檢查左子樹有沒有符合定義
        {
            return false;
        }else if(compare!=NULL&&root->val<=compare->val)//跟紀錄的節點比較
        {
            return false;
        }
        
        //更新紀錄的節點
        compare=root;
        
        //最後才往右走
        return isValidBST(root->right);
    }
};