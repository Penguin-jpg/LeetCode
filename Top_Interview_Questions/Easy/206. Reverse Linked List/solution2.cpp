/**
 * 想法: solution1 遞迴版
 * 時間: O(n), 空間: O(n)
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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }
        return reverse(nullptr, head);
    }

    ListNode *reverse(ListNode *pre, ListNode *current)
    {
        if (current == nullptr)
        {
            return pre;
        }
        ListNode *next = current->next;
        current->next = pre;
        return reverse(current, next);
    }
};