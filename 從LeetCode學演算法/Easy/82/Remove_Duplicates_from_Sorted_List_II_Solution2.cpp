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
            參考的方法
            時間複雜度O(n)、空間複雜度O(1)
            使用dummy node
        */

        if (head == NULL)
        {
            return head;
        }

        ListNode *dummy = new ListNode(0, head);
        ListNode *previous = dummy;
        ListNode *current = head;

        while (current != NULL)
        {
            while (current->next != NULL && current->val == current->next->val)
            {
                current = current->next;
            }

            //沒有進入上面的迴圈(previous和current剛好一前一後)
            if (previous->next == current)
            {
                previous = previous->next;
            }
            else //進入了上面的迴圈(previous的下一個不會是current，因為current移動過了)
            {
                previous->next = current->next;
            }

            current = current->next;
        }

        return dummy->next;
    }
};