/**
 * 參考想法: solution2 的加強版，可以直接透過快慢指標找到中間的 node，省掉長度計算
 * 時間: O(n)，空間: O(1)
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
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = reverseList(slow); // slow should be the middle node
        fast = head;              // make fast back to head
        while (slow != nullptr)
        {
            if (slow->val != fast->val)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr, *current = head, *next = head;
        while (current != nullptr)
        {
            next = current->next;
            current->next = pre;
            pre = current;
            current = next;
        }
        return pre;
    }
};