#include <vector>
using namespace std;

/**
 * 參考解答: 用 dp+greedy 解，dp[i] 代表從 0~i 能跳的最大值
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    bool canJump(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 0);
        int goal = nums.size() - 1;
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (dp[i - 1] < i) // cannot even reach index i
            {
                return false;
            }
            dp[i] = max(i + nums[i], dp[i - 1]);
            if (dp[i] >= goal)
            {
                return true;
            }
        }
        return dp[goal] >= goal;
    }
};