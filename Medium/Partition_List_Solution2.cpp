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
            參考的方法
            時間複雜度O(n)、空間複雜度O(1)
            將小於x的都接在ite1，大於等於x的都接在ite2，最後將ite2接到ite1後面
        */

        if (head == NULL)
        {
            return head;
        }

        ListNode *dummy1 = new ListNode(0);
        ListNode *dummy2 = new ListNode(0);
        ListNode *ite1 = dummy1;
        ListNode *ite2 = dummy2;

        while (head != NULL)
        {
            //紀錄下一個節點(避免之後動到head導致資訊遺失)
            ListNode *temp = head->next;

            if (head->val < x)
            {
                ite1->next = head;
                ite1 = ite1->next;
                ite1->next = NULL;
            }
            else
            {
                ite2->next = head;
                ite2 = ite2->next;
                ite2->next = NULL;
            }

            head = temp;
        }

        if (dummy1->next == NULL)
        {
            return dummy2->next;
        }

        if (dummy2->next == NULL)
        {
            return dummy1->next;
        }

        ite1->next = dummy2->next;

        return dummy1->next;
    }
};