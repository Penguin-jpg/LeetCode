#include <unordered_map>
using namespace std;

/**
 * 想法: 透過 hash map 把走過的 ListNode 存起來，如果目前走的點已經出現在 hash map 中，則代表有環
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
    bool hasCycle(ListNode *head)
    {
        unordered_map<ListNode *, bool> table;
        ListNode *current = head;
        while (current != nullptr)
        {
            if (table.count(current))
            {
                return true;
            }
            table[current] = true;
            current = current->next;
        }
        return false;
    }
};