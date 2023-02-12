#include <queue>
using namespace std;

/**
 * 想法: 做 level-order 的 traversal，並用 previous 和 current 分別記錄上一個節
 * 點及目前的節點，每次迴圈開始都更新上一個節點及目前節點的位置，並把上一個節點
 * 的 next 接到目前節點
 * 時間: O(n), 空間: O(2^logn)
 */

class Node
{
  public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL)
    {
    }

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL)
    {
    }

    Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next)
    {
    }
};

class Solution
{
  public:
    Node *connect(Node *root)
    {
        if (root == NULL)
        {
            return root;
        }
        queue<Node *> nodes;
        nodes.push(root);
        int size = nodes.size();
        Node *previous = NULL, *current = NULL;
        vector<vector<int>> values;
        while (!nodes.empty())
        {
            for (int i = 0; i < size; i++)
            {
                previous = current;      // update previous node
                current = nodes.front(); // update current node
                nodes.pop();
                if (current->left != NULL)
                {
                    nodes.push(current->left);
                }
                if (current->right != NULL)
                {
                    nodes.push(current->right);
                }
                if (previous != NULL)
                {
                    previous->next = current;
                }
            }
            size = nodes.size();
            current = NULL; // initialize current node so it won't confuse it with nodes from last level
        }
        return root;
    }
};