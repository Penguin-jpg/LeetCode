#include <unordered_map>
using namespace std;

/**
 * 想法: 將原先對應的 random pointers 存起來，再將這些 random pointers 所對應的
 * index 也存起來，建立好所有新 Node 之後，開始將 random pointer 接起來，由於相
 * 對位置是一樣的，所以只需要透過先前建立的兩個 hash map 就能重新按照位置連接
 * random pointers
 * 時間: O(n^2), 空間: O(n)
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
        Node *dummy = new Node(0), *newHead = dummy;
        int i = 0;
        while (head != NULL)
        {
            newHead->next = new Node(head->val);
            newHead = newHead->next;
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
                Node *randomPointer = dummy->next;
                // since relative position is the same, just move to the index
                for (int i = 0; i < index; i++)
                {
                    randomPointer = randomPointer->next;
                }
                newHead->random = randomPointer;
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