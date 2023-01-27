/**
 * 想法: 先算出總長度，再將長度扣掉 n，就能得到是第幾個節點要被刪掉，透過 previous,
 * current, next 三個 pointer 來完成刪除
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int length = getLength(head);
        if (length == n) // remove the first node
        {
            return head->next;
        }
        ListNode *previous = nullptr, *current = head, *next = head;
        int target = length - n; // target node to remove
        int counter = 0;         // track where current is now
        while (current != nullptr)
        {
            next = current->next;
            if (counter == target)
            {
                previous->next = next;
                break;
            }
            previous = current;
            current = next;
            counter++;
        }
        return head;
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
};