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
    vector<vector<int>> levelOrder(TreeNode* root) {
        /*
            我的方法1
            時間複雜度O(n)、空間複雜度O(n)
            標準level-order作法(BFS)
        */

        vector<vector<int>> nums;
        
        if(root==NULL)
        {
            return nums;
        }
        
        queue<TreeNode*> nodes;
        nodes.push(root);
        vector<int> temp;
        int size=0;
        
        while(!nodes.empty())
        {
            size=nodes.size();
            temp.clear();
            
            for(int n=0;n<size;n++)
            {
                TreeNode* current=nodes.front();
                nodes.pop();
                temp.push_back(current->val);
                
                if(current->left!=NULL)
                {
                    nodes.push(current->left);
                }
                if(current->right!=NULL)
                {
                    nodes.push(current->right);
                }
            }
            
            nums.push_back(temp);
        }
        
        return nums;
    }
};