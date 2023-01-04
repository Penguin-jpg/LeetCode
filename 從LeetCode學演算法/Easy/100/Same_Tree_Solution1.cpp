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
    stack<int> nums1;
    stack<int> nums2;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        /*
            我的方法
            複雜度:O(n + length of stack)
            先將兩棵樹的值分別存在兩個stack，再比對stack的值是否都相同
        */

        traversal(p,nums1);
        traversal(q,nums2);
        
        //stack大小不同就一定錯
        if(nums1.size()!=nums2.size())
        {
            return false;
        }else
        {
            //比較stack內的數是否都相同
            while(!nums1.empty())
            {
                if(nums1.top()!=nums2.top())
                {
                    return false;
                }else
                {
                    nums1.pop();
                    nums2.pop();
                }
            }
            
            return true;
        }
    }
    
    //以in-order方式尋訪整棵樹
    void traversal(TreeNode* node,stack<int>& nums)
    {
        if(node==NULL)
        {
            //遇到NULL就放入範圍外的值
            nums.push(-10001);
            return;
        }else
        {
            //順序:中->左->右
            nums.push(node->val);
            traversal(node->left,nums);
            traversal(node->right,nums);
        }
    }
};