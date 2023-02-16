#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 想法: 將新的 Node 都存到陣列內，最後在接 random pointer 的時候就能用 index 直接跳過去
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
        unordered_map<Node *, Node *> randomPointers; // store original random pointers
        unordered_map<Node *, int> indices;           // store original pointers and corresponding indices
        vector<Node *> newNodes;                      // store new nodes
        Node *dummy = new Node(0), *newHead = dummy;
        int i = 0;
        while (head != NULL)
        {
            newHead->next = new Node(head->val);
            newHead = newHead->next;
            newNodes.push_back(newHead);
            randomPointers[newHead] = head->random;
            indices[head] = i;
            head = head->next;
            i++;
        }
        newHead = dummy->next;
        while (newHead != NULL)
        {
            if (randomPointers[newHead] != NULL)
            {
                int index = indices[randomPointers[newHead]]; // get index from pointer address
                newHead->random = newNodes[index];
            }
            else
            {
                newHead->random = NULL;
            }
            newHead = newHead->next;
        }
        return dummy->next;
    }
};