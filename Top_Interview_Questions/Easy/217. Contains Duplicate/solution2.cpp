#include <algorithm>
using namespace std;

/**
 * 想法: 先排序，再兩兩前後相剪，如果有 0，就回傳 true
 * 時間: O(nlogn), 空間: O(1)
 */

class Solution
{
  public:
    bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] == 0)
            {
                return true;
            }
        }
        return false;
    }
};