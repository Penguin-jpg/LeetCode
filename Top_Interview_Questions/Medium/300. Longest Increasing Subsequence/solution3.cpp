#include <vector>
using namespace std;

/**
 * 參考解答: 用 dp table法，dp[i] 代表到 i 的最大長度
 * 時間: O(n^2), 空間: O(n)
 */

class Solution
{
  public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 1);
        int maxLength = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    // either choose the current max length or max length of j
                    // and inclues i
                    dp[i] = max(dp[i], 1 + dp[j]);
                    maxLength = max(maxLength, dp[i]);
                }
            }
        }
        return maxLength;
    }
};