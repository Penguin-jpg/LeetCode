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
            我的方法2
            時間複雜度O(n)、空間複雜度O(n);
            Iterative
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
        
        stack<TreeNode*> temp; //暫存右邊節點，後進先出
        queue<TreeNode*> nodes;
        nodes.push(root);
        
        while(!nodes.empty())
        {
            TreeNode* current=nodes.front();
            nums.push_back(current->val);
            nodes.pop();
            
            if(current->right!=NULL)
            {
                temp.push(current->right);
            }
            if(current->left!=NULL)
            {
                nodes.push(current->left);
            }else if(current->left==NULL&&!temp.empty()) //左邊為空的時候就拿出原本暫存的右節點
            {
                nodes.push(temp.top());
                temp.pop();
            }
        }
    }
};