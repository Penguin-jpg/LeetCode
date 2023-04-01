#include <algorithm>
#include <vector>
using namespace std;

/**
 * 想法: 先將 lists flatten 後存到另一個陣列，再由大到小排序，最後用左接的方式接起來
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

bool cmp(ListNode *a, ListNode *b)
{
    return a->val > b->val;
}

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
        vector<ListNode *> nodes;
        for (int i = 0; i < lists.size(); i++)
        {
            while (lists[i] != nullptr)
            {
                nodes.push_back((lists[i]));
                lists[i] = lists[i]->next;
            }
        }
        sort(nodes.begin(), nodes.end(), cmp);
        for (int i = 0; i < nodes.size(); i++)
        {
            nodes[i]->next = previous;
            previous = nodes[i];
        }
        return previous;
    }
};