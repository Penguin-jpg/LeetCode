#include <queue>
using namespace std;

/**
 * 參考解答: 可以將順序改成由左到右，就不需要檢查 previous 是否為 NULL
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
                if (current->right != NULL)
                {
                    nodes.push(current->right);
                }
                if (current->left != NULL)
                {
                    nodes.push(current->left);
                }
                current->next = previous;
            }
            size = nodes.size();
            current = NULL; // initialize current node so it won't confuse it with nodes from last level
        }
        return root;
    }
};