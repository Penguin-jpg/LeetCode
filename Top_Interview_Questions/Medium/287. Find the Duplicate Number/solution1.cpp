#include <algorithm>
#include <vector>
using namespace std;

/**
 * 想法: 先排序，再找前後相減是 0 的 (會過，但不符合題目要求的不能改 nums)
 * 時間: O(nlogn), 空間: O(1)
 */

class Solution
{
  public:
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] - nums[i + 1] == 0)
            {
                return nums[i];
            }
        }
        return nums[0];
    }
};