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
    vector<int> preorderTraversal(TreeNode* root) {
        /*
            參考的方法
            時間複雜度O(n)、空間複雜度O(n)
            利用stack後進先出的特性，只要以右->左->根的順序加入stack，出來的順序就會是根->左->右
        */

        vector<int> nums;
        preorder(nums,root);
        return nums;
    }
    
    void preorder(vector<int>& nums,TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        
        stack<TreeNode*> nodes;
        nodes.push(root);
        
        while(!nodes.empty())
        {
            TreeNode* current=nodes.top();
            nodes.pop();
            nums.push_back(current->val);
            
            if(current->right!=NULL)
            {
                nodes.push(current->right);
            }
            if(current->left!=NULL)
            {
                nodes.push(current->left);
            }
        }
    }
};