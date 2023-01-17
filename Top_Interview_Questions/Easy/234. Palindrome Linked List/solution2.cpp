/**
 * 想法: 先算長度，並將後半的 list 反向串接，兩邊分別從頭配對，如果都一樣就是回文
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
        int length = getLength(head);
        ListNode *front = head;
        ListNode *back = head;
        for (int i = 0; i < length / 2; i++)
        {
            back = back->next;
        }
        reverseList(back);
        while (back != nullptr)
        {
            if (front->val != back->val)
            {
                return false;
            }
            front = front->next;
            back = back->next;
        }
        return true;
    }

    int getLength(ListNode *head)
    {
        int length = 0;
        ListNode *current = head;
        while (current != nullptr)
        {
            length++;
            current = current->next;
        }
        return length;
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