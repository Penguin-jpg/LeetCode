#include <algorithm>
#include <vector>
using namespace std;

/**
 * 想法: 先排序，再跑一次迴圈，檢查哪組數字前後差距大於 1，其中間就是缺失的數字
 * 時間: O(nlogn), 空間: O(1)
 */

class Solution
{
  public:
    int missingNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] > 1)
            {
                return i;
            }
        }
        // special cases for those cannot be detected
        return nums[0] != 0 ? 0 : nums.size();
    }
};