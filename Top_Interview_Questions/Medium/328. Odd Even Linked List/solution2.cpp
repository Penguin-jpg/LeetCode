/**
 * 想法: 從第一個和第二個開始，每次都取 next->next 分別組成 odd 和 even 後再接
 * 上，檢查時必須確定 odd->next 和 even->next 都不是 nullptr，如果檢查的是
 * odd!=nullptr && even!=nullptr，就會導致出迴圈時，odd 是 nullptr，無法直接存取 next
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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *odd = head, *evenDummy = head->next, *even = evenDummy;
        while (odd->next != nullptr && even->next != nullptr)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenDummy;
        return head;
    }
};