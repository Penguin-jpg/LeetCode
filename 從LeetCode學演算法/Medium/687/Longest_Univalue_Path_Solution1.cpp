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
class Solution
{
public:
    int longestUnivaluePath(TreeNode *root)
    {
        /*
            參考的方法
            時間複雜度O(n)、空間複雜度O(log(n))
            每個節點都只有兩種延伸情況:
            1. 選左邊或右邊
            2. 左右都選，但要記得最後路徑必須能一筆劃走完，否則是無效的
            最後找出最大值
        */

        if (root == NULL)
        {
            return 0;
        }

        int maxLength = 0;
        count(root, root->val, maxLength);
        return maxLength;
    }

    int count(TreeNode *root, int target, int &maxLength)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left = count(root->left, root->val, maxLength);
        int right = count(root->right, root->val, maxLength);
        //左右都選
        maxLength = max(maxLength, left + right);

        if (target == root->val)
        {
            //選左邊或右邊
            return max(left, right) + 1;
        }

        return 0;
    }
};