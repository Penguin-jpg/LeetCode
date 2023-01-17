#include <deque>
using namespace std;

/**
 * 想法: 透過 deque 儲存經過的 node，最後從頭尾開始 pop ，如果最後 deque 為空，就是回文
 * 時間: O(n)，空間: O(n)
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
    bool isPalindrome(ListNode *head)
    {
        deque<int> nums;
        ListNode *current = head;
        while (current != nullptr)
        {
            nums.push_back(current->val);
            current = current->next;
        }
        int size = nums.size();
        for (int i = 0; i < size / 2; i++)
        {
            if (nums.front() != nums.back())
            {
                return false;
            }
            nums.pop_front();
            nums.pop_back();
        }
        return nums.empty() || nums.size() == 1;
    }
};