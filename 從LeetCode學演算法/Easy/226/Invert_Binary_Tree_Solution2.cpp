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
    TreeNode* invertTree(TreeNode* root) {
        /*
            我的方法2
            時間複雜度O(n)、空間複雜度O(n)
            利用BFS由前面的節點開始反轉，最後才做後面的節點
        */

        if(root==NULL)
        {
            return root;
        }
        
        int size=0;
        queue<TreeNode*> nodes;
        TreeNode* current=NULL;
        TreeNode* temp=NULL;
        nodes.push(root);
        
        while(!nodes.empty())
        {
            size=nodes.size();
            
            for(int i=0;i<size;i++)
            {
                current=nodes.front();
                nodes.pop();
                
                if(current->left!=NULL)
                {
                    nodes.push(current->left);
                }
                if(current->right!=NULL)
                {
                    nodes.push(current->right);
                }
                
                temp=current->left;
                current->left=current->right;
                current->right=temp;
            }
        }
        
        return root;
    }
};