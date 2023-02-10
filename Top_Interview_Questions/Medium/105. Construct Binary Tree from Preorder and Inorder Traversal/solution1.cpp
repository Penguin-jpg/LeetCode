#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 參考解答: 觀察到的規律有下列兩個：
 *      1. preorder 開頭一定是 root
 *      2. 由於每個元素都 unique，所以可以根據第一點將 inorder 在 root 前的元素
 *         都放在左子樹，在 root 後的元素都放在右子樹
 * 透過第一及第二點，可以遞迴將整個陣列切個成多個 root、左子樹及右子樹，再
 * 將它們組合起來即可：
 * 時間: O(n), 空間: O(n)
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> inorderIndices; // store inorder[i] and i
        int preorderLeft = 0;                   // points to index of root in preoder
        for (int i = 0; i < preorder.size(); i++)
        {
            inorderIndices[inorder[i]] = i;
        }
        return build(preorder, inorder, inorderIndices, preorderLeft, 0, inorder.size() - 1);
    }

    // pass preorderLeft as refernece to automatically point to the root we need
    // as the building process goes
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &inorderIndices,
                    int &preorderLeft, int inorderLeft, int inorderRight)
    {
        if (inorderLeft > inorderRight)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[preorderLeft]);
        int rootIndex = inorderIndices[root->val];
        preorderLeft++;
        root->left = build(preorder, inorder, inorderIndices, preorderLeft, inorderLeft, rootIndex - 1);
        root->right = build(preorder, inorder, inorderIndices, preorderLeft, rootIndex + 1, inorderRight);
        return root;
    }
};