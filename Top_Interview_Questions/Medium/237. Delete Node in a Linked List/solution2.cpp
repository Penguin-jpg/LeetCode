/**
 * 想法: 改成遞迴
 * 時間: O(n), 空間: O(n)
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
        getNextVal(node);
    }

    int getNextVal(ListNode *node)
    {
        // since "node" won't be tail node, we can use next->next safely
        if (node->next->next == nullptr)
        {
            int val = node->val;
            node->val = node->next->val;
            node->next = nullptr;
            return val;
        }
        int val = node->val;
        node->val = getNextVal(node->next);
        return val;
    }
};