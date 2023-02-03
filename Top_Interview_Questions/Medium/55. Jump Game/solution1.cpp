#include <vector>
using namespace std;

/**
 * 想法: 用 dp table 法，將 dp[0] 初始化為 true，其他均為 false，將能走的範圍內
 * 全部的 dp[i] 均改為 true，若到某個 index j 而 dp[j] 為 false，就代表不可能可
 * 以到終點，直接回傳 false，若檢查出 dp[last_index]=true，就代表能到終點
 * 時間: O(a1*a2*...*a(n-1)), ai: 第 i 個元素的值, 空間: O(n)
 */

class Solution
{
  public:
    bool canJump(vector<int> &nums)
    {
        vector<bool> dp(nums.size(), false);
        int goal = nums.size() - 1;
        dp[0] = true;
        for (int i = 0; i < goal; i++)
        {
            if (dp[goal])
            {
                return true;
            }
            else if (!dp[i])
            {
                return false;
            }
            for (int j = 1; j <= nums[i] && i + j < nums.size(); j++)
            {
                dp[i + j] = true;
            }
        }
        return dp[goal];
    }
};