/**
 * 參考解答: 透過 two pointers 來解，先讓一個 fast 走 n 步後，slow 再開始走，這
 * 樣的話，fast 與 slow 永遠相距 n 步，也就是當 fast 抵達終點後，slow 應該在離終
 * 點 n 步的地方，但由於第 n 個節點是要刪除的，所以應該要在該節點前停下來，所以
 * 檢查條件應改為 fast->next!=nullptr，才能在 n-1 的地方停下
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
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n; i++) // fast pointer moves n steps ahead
        {
            fast = fast->next;
        }
        if (fast == nullptr) // move n times and reach the end, means that length of list is n
        {
            return head->next; // remove head
        }
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next; // skip the n-th node
        return head;
    }
};