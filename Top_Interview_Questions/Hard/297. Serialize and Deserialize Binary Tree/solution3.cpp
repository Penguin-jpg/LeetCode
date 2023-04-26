#include <string>
#include <vector>
using namespace std;

/**
 * 想法: 直接在 serialize 的時候用遞迴建立字串 (不會比 solution2 快，但可以直接
 * 轉換到 python 不用修改邏輯)
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

class Codec
{
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
        {
            return " ,";
        }
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        vector<int> values = splitByComma(data);
        int index = 0;
        return buildTree(values, index);
    }

    vector<int> splitByComma(string &str)
    {
        vector<int> values;
        int start = 0; // index that we should looking at
        while (true)
        {
            int lastPos = str.find(',', start); // last position found comma;
            if (lastPos == str.npos)
            {
                break;
            }
            string val = str.substr(start, lastPos - start); // cut the value out
            if (val == " ")
            {
                values.push_back(INT_MIN); // use INT_MIN to indicate null
            }
            else
            {
                values.push_back(stol(val));
            }
            start = lastPos + 1;
        }
        return values;
    }

    TreeNode *buildTree(vector<int> &values, int &index)
    {
        if (index >= values.size() || values[index] == INT_MIN)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(values[index]);
        index++;
        root->left = buildTree(values, index);
        index++;
        root->right = buildTree(values, index);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));