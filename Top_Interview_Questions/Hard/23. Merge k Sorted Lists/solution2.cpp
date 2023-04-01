#include <vector>
using namespace std;

/**
 * 想法: solution1 的優化版，可以在檢查 lists[i] 是否為 nullptr 時就順便找最小值，可以省一個迴圈
 * 時間: O(n1+(n1+n2)+(n1+n2+n3)...+(n1+n2+...+nk))
 * (不失一般性假設 n1>=n2>=...>=nk，worst case 下，每個 lists 剛好可以依序接完，
 * 但因無法提前得知，所以就會每個 lists 都會重複檢查很多次)
 * 空間: O(k)
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
        {
            return nullptr;
        }
        int k = lists.size();
        ListNode *dummy = new ListNode(), *result = dummy;
        while (true)
        {
            int counter = 0, minVal = INT_MAX, index = 0;
            for (int i = 0; i < k; i++)
            {
                if (lists[i] == nullptr)
                {
                    counter++;
                }
                else if (lists[i]->val < minVal)
                {
                    minVal = lists[i]->val;
                    index = i;
                }
            }
            if (counter == k)
            {
                break;
            }
            result->next = lists[index];
            result = result->next;
            lists[index] = lists[index]->next;
        }
        return dummy->next;
    }
};