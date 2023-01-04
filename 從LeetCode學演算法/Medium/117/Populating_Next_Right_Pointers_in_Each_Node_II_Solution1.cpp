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
            我的方法(大部分的人都這樣寫)
            時間複雜度O(n)、空間複雜度O(n)
            BFS
        */

        if (root == NULL)
        {
            return root;
        }

        queue<Node *> nodes;
        int size = 0;

        nodes.push(root);

        while (!nodes.empty())
        {
            size = nodes.size();

            while (size--)
            {
                Node *current = nodes.front();
                nodes.pop();

                //接上next
                if (size != 0)
                {
                    current->next = nodes.front();
                }
                else
                {
                    current->next = NULL;
                }

                //找到後續節點
                if (current->left != NULL)
                {
                    nodes.push(current->left);
                }

                if (current->right != NULL)
                {
                    nodes.push(current->right);
                }
            }
        }

        return root;
    }
};