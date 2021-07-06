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
    void flatten(TreeNode* root) {
        if(root==NULL)
        {
            return;
        }
        
        queue<TreeNode*> nodes;
        pre_order(root,nodes);
        
        TreeNode* current=nodes.front();
        TreeNode* next;
        nodes.pop();
        
        while(!nodes.empty())
        {
            next=nodes.front();
            nodes.pop();
            
            current->left=NULL;
            current->right=next;
            current=next;
        }
    }
    
    void pre_order(TreeNode* root,queue<TreeNode*>& nodes)
    {
        if(root==NULL)
        {
            return;
        }
        
        nodes.push(root);
        pre_order(root->left,nodes);
        pre_order(root->right,nodes);
    }
};