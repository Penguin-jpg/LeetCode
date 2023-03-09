/**
 * 想法: 由於題目不給 head，所以我們無法用一般的方式進行刪除(需要 previous)，所
 * 以改成從 node 開始，將其後的節點都往左移一位，最後再把 tail 改為 nullptr，來
 * 達到類似刪除的效果
 * (題目有說 node 只可能是 head 或中間的點，不會是 tail)
 * 時間: O(n), 空間: O(1)
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
    void deleteNode(ListNode *node)
    {
        ListNode *previous = nullptr;
        ListNode *current = node;
        ListNode *next = current->next;
        while (next != nullptr)
        {
            previous = current;
            current->val = next->val; // assign the value of next to current node to simulate left shift
            current = next;
            next = next->next;
        }
        previous->next = nullptr; // "previous" will stop at the last node and we make it point to nullptr to delete it
    }
};