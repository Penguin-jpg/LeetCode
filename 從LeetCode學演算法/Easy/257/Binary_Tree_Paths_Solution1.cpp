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
   vector<string> binaryTreePaths(TreeNode* root) {
        /*
            自己想(70%)加參考(30%)的方法
            時間複雜度O(n)
        */

        vector<string> results;
        traversal(root,"",results);
        return results;
    }
    
    void traversal(TreeNode* root,string path,vector<string>& results)
    {
        if(root->left==NULL&&root->right==NULL)
        {
            path+=to_string(root->val);
            results.push_back(path);
            return;
        }
        
        string temp=path+to_string(root->val)+"->";
        if(root->left!=NULL)
        {
            traversal(root->left,temp,results);
        }
        if(root->right!=NULL)
        {
            traversal(root->right,temp,results);
        }
    }
};