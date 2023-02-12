#include <queue>
using namespace std;

/**
 * 參考解答: 用 DFS 做，但 DFS 的問題在於進入到下一層之後就沒辦法存取 right，所
 * 以必須要透過父節點來建立 next 的關係，先將 root->left->next=right，再把
 * root->right->next=root->next->left (這部分其實就是讓右節點可以接到旁邊的子樹的左節點上)
 * 時間: O(n), 空間: O(logn)
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
        if (root->left != NULL)
        {
            root->left->next = root->right; // connect left to right
            if (root->next != NULL)         // connect subtree
            {
                root->right->next = root->next->left;
            }
            connect(root->left);
            connect(root->right);
        }
        return root;
    }
};