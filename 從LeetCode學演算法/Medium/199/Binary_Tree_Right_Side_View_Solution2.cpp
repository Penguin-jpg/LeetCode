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
            參考的方法2
            時間複雜度O(n)、空間複雜度O(log(n))
            用DFS，先將右邊的都找完，如果左邊還有沒被擋住的，再繼續找
        */

        vector<int> nums;
        int maxLevel=0;
        
        DFS(root,maxLevel,1,nums);
        
        return nums;
    }
    
    void DFS(TreeNode* root,int& maxLevel,int currentLevel,vector<int>& nums)
    {
        if(root==NULL)
        {
            return;
        }
        
        //還沒找到最後一層
        if(currentLevel>maxLevel)
        {
            maxLevel=currentLevel;
            nums.push_back(root->val);
        }
        
        //先找完右邊再找左邊
        DFS(root->right,maxLevel,currentLevel+1,nums);
        DFS(root->left,maxLevel,currentLevel+1,nums);
    }
};