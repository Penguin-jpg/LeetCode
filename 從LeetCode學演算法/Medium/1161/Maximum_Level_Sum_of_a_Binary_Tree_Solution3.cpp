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
            參考的方法(大部分的人都是這樣解)
            時間複雜度O(n)、空間複雜度O(n)
            透過迴圈將該層的所有節點的值相加，並在處理迴圈的同時就把下一層的所有節點都加入queue
        */

        int maxSum=INT_MIN;
        int minLevel=1;
        int level=1;
        queue<TreeNode*> nodes;
        nodes.push(root);
        
        while(!nodes.empty())
        {
            int sum=0;
            for(int n=nodes.size();n>0;n--)
            {
                TreeNode* current=nodes.front();
                nodes.pop();
                sum+=current->val;
                
                if(current->left!=NULL)
                {
                    nodes.push(current->left);
                }
                
                if(current->right!=NULL)
                {
                    nodes.push(current->right);
                }
            }
            
            if(sum>maxSum)
            {
                maxSum=sum;
                minLevel=level;
            }
            
            level++;
        }
        
        return minLevel;
    }
};