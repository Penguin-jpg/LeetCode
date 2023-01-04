/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr),invert right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {     
        /*
            我的方法1
            時間複雜度O(n)、空間複雜度O(log(n))
            利用DFS由後面的節點開始反轉，最後才做前面的節點
        */

        DFS(root);
        return root;
    }
    
    TreeNode* DFS(TreeNode* root)
    {
        if(root==NULL)
        {
            return root;
        }else if(root->right==NULL&&root->left==NULL)
        {
            return root;
        }
        
        //反轉(左子樹接到右邊，右子樹接到左邊)
        TreeNode* leftNode=DFS(root->left);
        TreeNode* rightNode=DFS(root->right);
        root->left=rightNode;
        root->right=leftNode;
        return root;
    }
};