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
     void flatten(TreeNode* root) {
         /*
            參考的方法2
            時間複雜度O(n)、空間複雜度O(n)
            利用stack紀錄節點，再透過先接左子樹的方式還原pre-order，有點類似我的方法改成迭代版
         */

        if (root==NULL)
        {
            return;
        }
        
        stack<TreeNode*> nodes;
        nodes.push(root);
        
        while (!nodes.empty()) {
            TreeNode* current = nodes.top();
            nodes.pop();
            
            if (current->right!=NULL)
            {
                nodes.push(current->right);
            }
            
            if (current->left!=NULL) 
            {
                nodes.push(current->left);
            }

            if (!nodes.empty()) 
            {
                current->right=nodes.top();
            }
            
            current->left=NULL; 
        }
    }
};