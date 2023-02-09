#include <deque>
#include <vector>
using namespace std;

/**
 * 想法: 透過 deque 來做到雙向 push, pop，並用一個變數紀錄目前是從左到右還是從右
 * 到左，當從左到右時，就從 deque 的 front 開始 pop，並且將子節點從左到右
 * push_back，這樣才能避免取 front 時把子節點也取出來，從右到左同理，只不過從
 * back 開始 pop，並將子節點由右到左 push_front(確保順序正確)
 * 時間: O(n), 空間: O(2^logn)
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        vector<vector<int>> results;
        deque<TreeNode *> nodes;
        nodes.push_back(root);
        int size = nodes.size();
        bool fromLeft = true; // start from left
        TreeNode *current = nullptr;
        while (!nodes.empty())
        {
            vector<int> values;
            for (int i = 0; i < size; i++)
            {
                if (fromLeft)
                {
                    // pop from front
                    current = nodes.front();
                    nodes.pop_front();
                    // push from back to prevent interference
                    if (current->left != nullptr)
                    {
                        nodes.push_back(current->left);
                    }
                    if (current->right != nullptr)
                    {
                        nodes.push_back(current->right);
                    }
                }
                else
                {
                    // pop from back
                    current = nodes.back();
                    nodes.pop_back();
                    // push to front to prevent interference
                    // also right first then left to keep the order correct
                    if (current->right != nullptr)
                    {
                        nodes.push_front(current->right);
                    }
                    if (current->left != nullptr)
                    {
                        nodes.push_front(current->left);
                    }
                }
                values.push_back(current->val);
            }
            size = nodes.size();
            results.push_back(values);
            fromLeft = !fromLeft; // change direction
        }
        return results;
    }
};