#include <string>
#include <vector>
using namespace std;

/**
 * 想法: solution1 改良版，切割時不做兩次 substr，只有切出數值時做，其他情況用
 * index 表示 (beats 10% 提升到 beats 97%)
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
        string result = "";
        inorder(root, result); // use the order [root,left,right] to store the whole tree
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        vector<int> values = splitByComma(data);
        int index = 0;
        return buildTree(values, index);
    }

    void inorder(TreeNode *root, string &result)
    {
        if (root == nullptr)
        {
            result += " ,";
            return;
        }
        result += to_string(root->val) + ",";
        inorder(root->left, result);
        inorder(root->right, result);
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