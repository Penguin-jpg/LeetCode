/**
 * 想法: 使用 two pointers 分別指向兩個 list 的開頭，同時走訪，並做判斷：
 *      1. 目前數字一樣大 -> 固定選 list2 的 node
 *      2. list1 數字比較大 -> 選 list2 的 node
 *      3. list2 數字比較大 -> 選 list1 的 node
 *      選完後的 list pointer 就到下一個 node，當其中一方為空時，就將另一方全部接上
 * 時間: O(n+m) n: list1 長度; n: list2 長度, 空間: O(n+m)
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
        {
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }

        ListNode *dummy = new ListNode(); // dummy pointer
        ListNode *result = dummy;
        ListNode *current1 = list1;
        ListNode *current2 = list2;

        while (current1 != nullptr && current2 != nullptr)
        {
            if (current1->val < current2->val)
            {
                result->next = current1;
                current1 = current1->next;
            }
            else
            {
                result->next = current2;
                current2 = current2->next;
            }
            result = result->next;
        }
        result->next = current1 != nullptr ? current1 : current2;
        return dummy->next;
    }
};