/**
 * 參考解答: 其實只需要把 node 的值先改成 node->next->val，再把 node->next 指向
 * node->next->next，就可完成替換(概念就是先把下一個點的值複製過來，再跳過他直接連到下下一個)
 * 時間: O(1), 空間: O(1)
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
        node->val = node->next->val;
        node->next = node->next->next;
    }
};