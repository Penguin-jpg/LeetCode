/**
 * 參考解答: solution1的更好寫法
 * 時間: O(n+m), 空間: O(1)
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
        int carry = 0;
        ListNode *dummy = new ListNode(0), *result = dummy;
        ListNode *current1 = l1, *current2 = l2;
        while (carry != 0 || current1 != nullptr || current2 != nullptr)
        {
            if (current1 != nullptr)
            {
                carry += current1->val;
                current1 = current1->next;
            }
            if (current2 != nullptr)
            {
                carry += current2->val;
                current2 = current2->next;
            }
            result->next = new ListNode(carry % 10);
            carry /= 10;
            result = result->next;
        }
        return dummy->next;
    }
};