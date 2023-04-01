#include <queue>
#include <vector>
using namespace std;

/**
 * 想法: 用 max-heap 把值都存起來，再依序把全部的 node 合起來(選用 max-heap 是因
 * 為可以透過左接的方式達到 O(1) 的 insert 複雜度，而且不需要 dummy node)
 * 時間: O(mlogm), m: n1+n2+...+nk, 空間: O(m)
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

class Compare
{
  public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val < b->val;
    }
};

class Solution
{
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
        {
            return nullptr;
        }
        ListNode *previous = nullptr;
        priority_queue<ListNode *, vector<ListNode *>, Compare> queue;
        for (int i = 0; i < lists.size(); i++)
        {
            while (lists[i] != nullptr)
            {
                queue.push(lists[i]);
                lists[i] = lists[i]->next;
            }
        }
        while (!queue.empty())
        {
            ListNode *current = queue.top();
            queue.pop();
            current->next = previous;
            previous = current;
        }
        return previous;
    }
};