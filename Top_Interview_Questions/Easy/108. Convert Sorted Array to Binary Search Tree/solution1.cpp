/**
 * 參考解答: 由於陣列已經排序過，所以可以把陣列拆成兩半，左半邊放左子樹，右半邊放右子樹(可以看成模擬二元搜尋法)
 * 時間: O(n), 空間: O(h)
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {
    }
};

class Solution
{
  public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return buildBST(nums, 0, nums.size() - 1);
    }

    TreeNode *buildBST(vector<int> &nums, int left, int right)
    {
        // cross the middle line
        if (left > right)
        {
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);
        return root;
    }
};