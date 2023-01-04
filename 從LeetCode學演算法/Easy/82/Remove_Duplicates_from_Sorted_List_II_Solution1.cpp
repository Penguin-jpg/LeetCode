/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        /*
            我的方法
            時間複雜度O(n)、空間複雜度O(1)
        */

        if (head == NULL)
        {
            return head;
        }

        int repeat = INT_MAX;
        ListNode *previous = NULL;
        ListNode *current = head;
        ListNode *nextNode = NULL;

        while (current != NULL)
        {
            nextNode = current->next;
            if (nextNode != NULL && current->val == nextNode->val)
            {
                repeat = current->val;
                while (current != NULL && current->val == repeat)
                {
                    if (previous != NULL)
                    {
                        previous->next = nextNode;
                    }
                    else
                    {
                        head = nextNode;
                    }
                    current = nextNode;
                    if (nextNode != NULL)
                    {
                        nextNode = nextNode->next;
                    }
                }
            }
            else
            {
                previous = current;
                current = nextNode;
            }
        }

        return head;
    }
};