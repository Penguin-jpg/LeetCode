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
            參考的方法1:
            複雜度O(n)，利用queue儲存要比較的節點，如果比對正確，就繼續往下找，直到找完整棵樹為止
        */

        //儲存要比對的節點
        queue<TreeNode*> nodes;
        
        //根節點為NULL一定為true
        if(root==NULL)
        {
            return true;
        }else
        {
            //先將左右子樹的根節點儲存
            nodes.push(root->left);
            nodes.push(root->right);
            
            while(!nodes.empty())
            {
                //取出節點
                TreeNode* l=nodes.front();
                nodes.pop();
                TreeNode* r=nodes.front();
                nodes.pop();
                
                //進行比對
                if(l==NULL&&r==NULL)
                {
                    continue;
                }else if(l==NULL||r==NULL)
                {
                    return false;
                }else if(l->val==r->val)
                {
                    nodes.push(l->left);
                    nodes.push(r->right);
                    nodes.push(l->right);
                    nodes.push(r->left);
                }else
                {
                    return false;
                }
            }
            
            return true;
        }
    }
};