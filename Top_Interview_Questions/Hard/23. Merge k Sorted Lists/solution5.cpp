#include <vector>
using namespace std;

/**
 * 參考解答: 用 divide and conquer 來做，每次都切一半，直到剩下兩個 list 的時候
 * 就 merge，最後全部合併起來就是答案
 * 時間: O(mlogm), m: n1+n2+...+nk, 空間: O(k)
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
        return merge(lists, 0, lists.size() - 1);
    }

    ListNode *merge(vector<ListNode *> &lists, int left, int right)
    {
        if (left == right)
        {
            return lists[left];
        }
        int mid = (left + right) / 2;
        ListNode *list1 = merge(lists, left, mid);
        ListNode *list2 = merge(lists, mid + 1, right);
        return mergeTwoLists(list1, list2);
    }

    ListNode *mergeTwoLists(ListNode *left, ListNode *right)
    {
        ListNode *dummy = new ListNode(), *result = dummy;
        while (left != nullptr && right != nullptr)
        {
            if (left->val < right->val)
            {
                result->next = left;
                left = left->next;
            }
            else
            {
                result->next = right;
                right = right->next;
            }
            result = result->next;
        }
        result->next = left != nullptr ? left : right;
        return dummy->next;
    }
};