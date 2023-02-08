/**
 * 參考解答: 紀錄路徑上的最小及最大值，才不會在檢查子樹沒問題，整體看卻出問題，
 * 第二個重點是記得不要每走一次就更新一次最大最小值(讓他維持在先前的節點進行比較)
 * 時間: O(n), 空間: O(logn)
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
    bool isValidBST(TreeNode *root)
    {
        return isValid(root, nullptr, nullptr);
    }

    bool isValid(TreeNode *root, TreeNode *minNode, TreeNode *maxNode)
    {
        if (root == nullptr)
        {
            return true;
        }
        if ((minNode != nullptr && root->val <= minNode->val) || (maxNode != nullptr && root->val >= maxNode->val))
        {
            return false;
        }
        // for left subtree, the max value is root->val and no min value
        // for right subtree the min value is root->val and no max value
        return isValid(root->left, minNode, root) && isValid(root->right, root, maxNode);
    }
};