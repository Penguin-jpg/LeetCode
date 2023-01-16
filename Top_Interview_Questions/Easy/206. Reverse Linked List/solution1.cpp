/**
 * 想法: 透過三個指標 pre, current, next 來分別指向上一個、目前以及下一個 node，
 * 每次都先將 next 移動到下一個 node，再把 current->next 指向 pre，最後將 current=pre, current=next,
 * next=next->next
 * 時間: O(n), 空間: O(1)
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
        ListNode *pre = nullptr, *current = head, *next = head;
        while (next != nullptr)
        {
            next = current->next;
            current->next = pre;
            pre = current;
            current = next;
        }
        current->next = pre;
        return current;
    }
};