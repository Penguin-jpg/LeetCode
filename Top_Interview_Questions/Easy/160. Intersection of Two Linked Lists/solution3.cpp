/**
 * 參考解答: 將開始交錯的節點記做 I，交錯 list 記做 C，所以 listA 可以表示為
 * A+I+C；listB 可以表示為 B+I+C，如果我們把 listA 接在 listB 之後，listB 也接在
 * listA 之後，則 listA 變為 A+I+C+B+I+C；listB 變成 B+I+C+A+I+C，可觀察到從第二
 * 個 I 開始的 list 長度相同了，就可以直接用 two pointers 的方式來解
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
        ListNode *currentA = headA;
        ListNode *currentB = headB;
        // loop stops only when currentA == currentB or
        // currentA=nullptr && currentB=nullptr
        while (currentA != currentB)
        {
            if (currentA != nullptr)
            {
                currentA = currentA->next;
            }
            else
            {
                // if reach the end of listA, make currentA point to headB to
                // simulate listB concat to listA, same reason for currentB
                currentA = headB;
            }
            if (currentB != nullptr)
            {
                currentB = currentB->next;
            }
            else
            {
                currentB = headA;
            }
        }
        return currentA;
    }
};