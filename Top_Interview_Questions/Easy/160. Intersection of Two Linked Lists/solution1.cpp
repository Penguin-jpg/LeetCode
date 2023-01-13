#include <unordered_map>
using namespace std;

/**
 * 想法: 先將 headA 全部走完並存到 hash map，再走一次 headB 並檢查是否有重複的 ListNode
 * 時間: O(n+m) n: listA長度; m: listB長度, 空間:O(n)
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
        unordered_map<ListNode *, bool> table;
        ListNode *current = headA;
        while (current != nullptr)
        {
            table[current] = true;
            current = current->next;
        }
        current = headB;
        while (current != nullptr)
        {
            if (table.count(current))
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
};