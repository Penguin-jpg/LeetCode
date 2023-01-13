#include <cmath>

/**
 * 想法: 由於不可能從較長 list 的開頭就開始出現 intersection，至少要從長度對齊的
 * 地方開始，所以先將較長的部分走到長度對齊短的 list 再用 two pointers 下去檢查
 * 時間: O(n+m), 空間:O(1)
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

class Solution
{
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int lengthA = getLength(headA);
        int lengthB = getLength(headB);
        int diff = abs(lengthA - lengthB);
        if (lengthA > lengthB)
        {
            for (int i = 0; i < diff; i++)
            {
                headA = headA->next;
            }
        }
        else
        {
            for (int i = 0; i < diff; i++)
            {
                headB = headB->next;
            }
        }
        ListNode *currentA = headA;
        ListNode *currentB = headB;
        while (currentA != nullptr && currentB != nullptr)
        {
            if (currentA == currentB)
            {
                return currentA;
            }
            currentA = currentA->next;
            currentB = currentB->next;
        }
        return nullptr;
    }

    int getLength(ListNode *head)
    {
        ListNode *current = head;
        int length = 0;
        while (current != nullptr)
        {
            length++;
            current = current->next;
        }
        return length;
    }
};