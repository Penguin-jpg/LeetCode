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
    vector<int> inorderTraversal(TreeNode* root) {
        /*
            我的方法2
            時間複雜度O(n)、空間複雜度O(number of nodes)
            迴圈
        */

        vector<int> nodes;
        stack<TreeNode*> temp;//儲存經過的節點
        TreeNode* current=root;//指向目前所在的節點

        while(current!=NULL||!temp.empty())
        {
            //先往左走到底
            while(current!=NULL)
            {
                temp.push(current);
                current=current->left;
            }
            
            //將current指向最左下角的節點
            current=temp.top();
            nodes.push_back(current->val);
            temp.pop();
            
            //左邊找完了，往右邊找
            current=current->right;
        }

        return nodes;
    }
};