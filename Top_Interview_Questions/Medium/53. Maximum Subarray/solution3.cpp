#include <vector>
using namespace std;

/**
 * 參考解答: 用 dp table法來解，dp[0][i] 代表到 0~i 的目前最大 subarray sum,
 * dp[1][i] 代表 0~i 真正最大的 subarray sum
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        vector<vector<int>> dp(2, vector<int>(nums.size()));
        dp[0][0] = dp[1][0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[0][i] = max(nums[i], nums[i] + dp[0][i - 1]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i]);
        }
        return dp[1][nums.size() - 1];
    }
};