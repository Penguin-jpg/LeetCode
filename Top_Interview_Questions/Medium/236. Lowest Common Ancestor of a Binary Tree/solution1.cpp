/**
 * 參考解答: 根據先前的觀察，從左右兩個子樹分別下手，並用 left 及 right 兩變數來
 * 記錄左右子樹的 ancestor (仍不確定是否為 common ancestor)，如果
 * root==nullptr||root==p||root==q，則回傳 root，代表目前的 root 是 ancestor，
 * 在這點基礎上將先前的想法更好的實作出來：
 *      1. left!=nullptr && right!=nullptr
 *         從左右子樹都找的到 ancestor，也就是 p,q 分散在左右子樹 -> root 是 LCA
 *      2. left!=nullptr && right==nullptr:
 *         只能在左子樹找到 ancestor，也就是 p,q 都在左子樹 -> left 是 LCA
 *      3. left==nullptr && right!=nullptr:
 *         只能在右子樹找到 ancestor，也就是 p,q 都在右子樹 -> right 是 LCA
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q)
        {
            return root;
        }
        // ancestor in left subtree of root (don't know if it is common ancestor yet)
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        // ancestor in right subtree of root (don't know if it is common ancestor yet)
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        // if there are ancestors in left subtree and right subtree, then p and
        // q are in different subtrees, so the LCA is root
        if (left != nullptr && right != nullptr)
        {
            return root;
        }
        else if (left != nullptr) // can only find ancestor in left subtree, left is LCA
        {
            return left;
        }
        return right; // can only find ancestor in right subtree, right is LCA
    }
};