#include <queue>
using namespace std;

/**
 * 參考解答: 同時用 DFS 和 BFS 的想法，每次都從最左邊的節點開始(每一層的第一個節
 * 點)， 並用 DFS 的方式把整層的接起來，透過 next pointer，就能達到類似 linked
 * list 的效果，不需要消耗額外的儲存空間
 * 時間: O(n), 空間: O(1)
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
        Node *head = root;
        while (root != NULL)
        {
            Node *current = root;
            while (current != NULL)
            {
                if (current->left != NULL)
                {
                    current->left->next = current->right;
                    if (current->next != NULL)
                    {
                        current->right->next = current->next->left;
                    }
                }
                current = current->next; // move along the same level
            }
            root = root->left; // to the first node of next level
        }
        return head;
    }
};