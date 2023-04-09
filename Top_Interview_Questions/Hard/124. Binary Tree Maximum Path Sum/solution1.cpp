#include <algorithm>
using namespace std;

/**
 * 參考解答: 首先要觀察出一個規則，就是若同時取左右子樹，則不能夠再繼續往下找，
 * 否則會導致路徑出現重複的節點，可以試著想一個例子，當取的路徑同時橫跨左右子樹
 * 時，不論想要再多取哪個節點，都會導致必須回頭的情況，了解這一點後就可以將這題
 * 拆成以下幾種情況：
 *      1. 取自己+左子樹的 max sum
 *      2. 取自己+右子樹的 max sum
 *      3. 取自己+左右子樹的 max sum
 * (在計算子樹的 max sum 時，若已知該 max sum 是負數，則根本不需要納入考慮，若
 * 加入的話一定會讓總和更小，所以直接取成 0，代表不取該子樹)
 * 詳細可參考：https://leetcode.com/problems/binary-tree-maximum-path-sum/editorial/
 * 時間: O(n), 空間: O(h), h: 樹高
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
    int maxPathSum(TreeNode *root)
    {
        int maxSum = INT_MIN;
        gainFromSubtree(root, maxSum);
        return maxSum;
    }

    int gainFromSubtree(TreeNode *root, int &maxSum)
    {
        if (root == nullptr)
        {
            return 0; // empty node return 0
        }
        // find the max sum of left subtree (if the sum is negative, then choose 0 instead)
        int leftMaxSum = std::max(gainFromSubtree(root->left, maxSum), 0);
        // same thing goes for right subtree
        int rightMaxSum = std::max(gainFromSubtree(root->right, maxSum), 0);
        // check if select both subtrees is bigger than current max sum
        maxSum = std::max(maxSum, root->val + leftMaxSum + rightMaxSum);
        // only choose from left max sum or right max sum
        return root->val + std::max(leftMaxSum, rightMaxSum);
    }
};