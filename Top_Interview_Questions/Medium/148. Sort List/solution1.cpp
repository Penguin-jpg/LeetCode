#include <algorithm>
#include <vector>
using namespace std;

/**
 * 想法: 先將 list 的值全部存到陣列，對陣列做 quick sort，再把值填回去
 * 時間: O(nlogn), 空間: O(n)
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
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }
        vector<int> nums;
        ListNode *current = head;
        while (current != nullptr)
        {
            nums.push_back(current->val);
            current = current->next;
        }
        sort(nums.begin(), nums.end());
        current = head;
        for (int i = 0; i < nums.size(); i++)
        {
            current->val = nums[i];
            current = current->next;
        }
        return head;
    }
};