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
    vector<int> rightSideView(TreeNode* root) {
        /*
            參考的方法1
            時間複雜度O(n)、空間複雜度O(n)
            利用level-order traversal，每層的最後一個節點即為答案
        */

        vector<int> nums;
        
        if(root==NULL)
        {
            return nums;
        }
        
        queue<TreeNode*> nodes;
        nodes.push(root);
        int size=0;
        int lastNodeVal=0;
        
        while(!nodes.empty())
        {
            size=nodes.size();
            for(int n=0;n<size;n++)
            {
                TreeNode* current=nodes.front();
                nodes.pop();
                lastNodeVal=current->val;
                
                if(current->left!=NULL)
                {
                    nodes.push(current->left);
                }
                if(current->right!=NULL)
                {
                    nodes.push(current->right);
                }
            }           
            
            nums.push_back(lastNodeVal);
        }
        
        return nums;
    }
};