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
    int maxLevelSum(TreeNode* root) {
        /*
            我的方法2
            時間複雜度O(n)、空間複雜度O(n)
            利用DFS遞迴的特性來更新傳入的level，算出每一層總和後，再比較大小
        */

        unordered_map<int,int> sums;
        DFS(root,1,sums);
        
        int maxSum=sums[1];
        int minLevel=1;
        
        for(auto& it:sums)
        {
            if(it.second>maxSum)
            {
                maxSum=it.second;
                minLevel=it.first;
            }
        }
        
        return minLevel;
    }
    
    void DFS(TreeNode* root,int level,unordered_map<int,int>& sums)
    {
        if(root==NULL)
        {
            return;
        }
        
        sums[level]+=root->val;
        DFS(root->left,level+1,sums);
        DFS(root->right,level+1,sums);
    }
};