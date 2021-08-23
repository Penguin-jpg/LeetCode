/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        /*
            參考的方法1
            時間複雜度O(n)、空間複雜度O(1)
            要連接的地方:current->left接到current->right、current->right接到current->next->left
            這幾個點全部連起來後就是答案
        */

        if (root == NULL)
        {
            return root;
        }

        //每層的最左邊節點
        Node *firstNode = root;

        while (firstNode != NULL)
        {
            Node *current = firstNode;

            while (current != NULL)
            {
                if (current->left != NULL)
                {
                    current->left->next = current->right;
                }

                if (current->right != NULL && current->next != NULL)
                {
                    current->right->next = current->next->left;
                }

                current = current->next;
            }

            firstNode = firstNode->left;
        }

        return root;
    }
};