/**
 * 想法: solution1遞迴版
 * 時間: O(n+m), 空間: O(n+m)
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};

class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return addLists(l1, l2, 0);
    }

    ListNode *addLists(ListNode *l1, ListNode *l2, int carry)
    {
        ListNode *result = nullptr;
        if (l1 == nullptr && l2 == nullptr)
        {
            result = carry == 1 ? new ListNode(carry) : nullptr;
        }
        else if (l1 == nullptr)
        {
            result = new ListNode((l2->val + carry) % 10);
            result->next = addLists(l1, l2->next, (l2->val + carry) / 10);
        }
        else if (l2 == nullptr)
        {
            result = new ListNode((l1->val + carry) % 10);
            result->next = addLists(l1->next, l2, (l1->val + carry) / 10);
        }
        else
        {
            result = new ListNode((l1->val + l2->val + carry) % 10);
            result->next = addLists(l1->next, l2->next, (l1->val + l2->val + carry) / 10);
        }
        return result;
    }
};