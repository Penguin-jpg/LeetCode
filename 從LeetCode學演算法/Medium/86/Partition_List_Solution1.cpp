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
    ListNode *partition(ListNode *head, int x)
    {
        /*
            我的方法
            時間複雜度o(n)、空間複雜度O(m)(m:符合條件的節點數)
            透過移除符合條件的節點並儲存起來，最後將這些節點重新接回前面
        */

        if (head == NULL)
        {
            return head;
        }

        ListNode *dummy = new ListNode(0, head);
        ListNode *previous = dummy;
        ListNode *current = head;
        ListNode *nextNode = NULL;
        stack<ListNode *> nodes;

        //找出符合條件的節點並移除
        while (current != NULL)
        {
            nextNode = current->next;
            if (current->val < x)
            {
                nodes.push(current);
                previous->next = nextNode;
                current = nextNode;
                if (nextNode != NULL)
                {
                    nextNode = nextNode->next;
                }
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }

        //把移除的節點重新插入
        while (nodes.size() != 0)
        {
            //插在最左邊
            ListNode *node = nodes.top();
            nodes.pop();
            node->next = dummy->next;
            dummy->next = node;
        }

        return dummy->next;
    }
};