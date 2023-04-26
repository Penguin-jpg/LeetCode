#include <string>
#include <vector>
using namespace std;

/**
 * 想法: 用 inorder 的方式走訪一次並存成字串(用逗點隔開，遇到 null 就留空
 * 格)，deserialize 就透過逗點切割，再照著順序建一次就好
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
        while (true)
        {
            int lastPos = str.find(','); // last position found comma;
            if (lastPos == str.npos)
            {
                break;
            }
            string val = str.substr(0, lastPos); // cut the value out
            if (val == " ")
            {
                values.push_back(INT_MIN); // use INT_MIN to indicate null
            }
            else
            {
                values.push_back(stol(val));
            }
            str = str.substr(lastPos + 1);
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