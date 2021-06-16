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
            我的方法2
            時間複雜度O(n)、空間複雜度O(n)
            用DFS的方式找
        */

        vector<vector<int>> nums;
        map<int,vector<int>> vals;
        
        DFS(root,0,nums,vals);
        
        for(auto& it:vals)
        {
            nums.push_back(it.second);
        }
        
        return nums;
    }
    
    void DFS(TreeNode* root,int level,vector<vector<int>>& nums,map<int,vector<int>>& vals)
    {
        if(root==NULL)
        {
            return;
        }
        
        vals[level].push_back(root->val);
        DFS(root->left,level+1,nums,vals);
        DFS(root->right,level+1,nums,vals);
    }
};