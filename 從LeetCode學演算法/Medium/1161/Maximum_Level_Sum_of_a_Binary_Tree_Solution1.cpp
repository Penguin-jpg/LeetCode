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
            我的方法(正確性應該沒什麼問題，但超時)
            時間複雜度O(n^2)(BFS+找level)、空間複雜度O(n)
            利用BFS找到每層的總和，再比較出最小層與最大值
        */

        unordered_map<int,int> sums;
        int level=1;
        queue<TreeNode*> nodes;
        nodes.push(root);
        
        while(!nodes.empty())
        {
            TreeNode* current=nodes.front();
            nodes.pop();
            level=getLevel(root,current->val,1);
            sums[level]+=current->val;
            current->val=INT_MIN;
            
            if(current->left!=NULL)
            {
                nodes.push(current->left);
            }
            
            if(current->right!=NULL)
            {
                nodes.push(current->right);
            }
        }
        
        int max=sums[1];
        int minLevel=1;
        
        for(auto& it:sums)
        {
            if(it.second>max)
            {
                max=it.second;
                minLevel=it.first;
            }
        }
        
        return minLevel;
    }
    
    int getLevel(TreeNode* node,int val,int level)
    {
        if(node==NULL)
        {
            return 0;
        }
        
        if(node->val==val)
        {
            return level;
        }
        
        int leftLevel=getLevel(node->left,val,level+1);
        int rightLevel=getLevel(node->right,val,level+1);
        
        if(leftLevel!=0&&rightLevel!=0)
        {
            return min(leftLevel,rightLevel);
        }else
        {
            return leftLevel==0?rightLevel:leftLevel;
        }
    }
};