#include <unordered_map>
using namespace std;

/**
 * 參考解答: 其實只需要一個 hash map 儲存原本的 Node 以及其對應的新 Node，最後再將全部接起來就好
 * 時間: O(n), 空間: O(n)
 */

class Node
{
  public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
  public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
        {
            return head;
        }
        unordered_map<Node *, Node *> table;
        Node *current = head;
        while (current != NULL)
        {
            table[current] = new Node(current->val);
            current = current->next;
        }
        current = head;
        while (current != NULL)
        {
            // next of new node is correspond to new node of original next
            table[current]->next = table[current->next];
            // random of new node is correspond to new node of original random
            table[current]->random = table[current->random];
            current = current->next;
        }
        return table[head];
    }
};