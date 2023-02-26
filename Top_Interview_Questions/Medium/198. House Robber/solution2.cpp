#include <vector>
using namespace std;

/**
 * 參考解答: 用 dp table法解，dp[i] 代表從 i 開始能偷到的最大總額，我們可以套用
 * solution1 所找到的關係式
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp.back();
    }
};