/**
 * 想法: 透過疊代將兩數相加，建立新節點並把進位帶到下次計算，當走到結尾後就會是
 * 完整的新 list
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
        int sum = 0, carry = 0;
        ListNode *dummy = new ListNode(0), *result = dummy;
        ListNode *current1 = l1, *current2 = l2;
        while (current1 != nullptr && current2 != nullptr)
        {
            sum = current1->val + current2->val + carry;
            result->next = new ListNode(sum % 10);
            carry = sum / 10;
            current1 = current1->next;
            current2 = current2->next;
            result = result->next;
        }
        while (current1 != nullptr) // finish l1
        {
            sum = current1->val + carry;
            result->next = new ListNode(sum % 10);
            carry = sum / 10;
            current1 = current1->next;
            result = result->next;
        }
        while (current2 != nullptr) // finish l2
        {
            sum = current2->val + carry;
            result->next = new ListNode(sum % 10);
            carry = sum / 10;
            current2 = current2->next;
            result = result->next;
        }
        if (carry == 1)
        {
            result->next = new ListNode(carry);
        }
        return dummy->next;
    }
};