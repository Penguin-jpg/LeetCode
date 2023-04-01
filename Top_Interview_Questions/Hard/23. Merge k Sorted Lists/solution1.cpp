#include <vector>
using namespace std;

/**
 * 想法: 用 k pointers 來做，邏輯和 merge 兩個 sorted list 差不多，但是因為無法
 * 確定到底會剩下幾個沒有合併完成，所以不能用原本把剩下的直接接上去的方式，改成
 * 在同一個迴圈內檢查目前的 head 是否全部都為空，是的話就代表接完了
 * 時間: O(n1+(n1+n2)+(n1+n2+n3)...+(n1+n2+...+nk)), 空間: O(k)
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
            int counter = 0;
            for (int i = 0; i < k; i++)
            {
                if (lists[i] == nullptr)
                {
                    counter++;
                }
            }
            if (counter == k)
            {
                break;
            }
            int minVal = INT_MAX, index = 0;
            for (int i = 0; i < k; i++)
            {
                if (lists[i] != nullptr && lists[i]->val < minVal)
                {
                    minVal = lists[i]->val;
                    index = i;
                }
            }
            result->next = lists[index];
            result = result->next;
            lists[index] = lists[index]->next;
        }
        return dummy->next;
    }
};