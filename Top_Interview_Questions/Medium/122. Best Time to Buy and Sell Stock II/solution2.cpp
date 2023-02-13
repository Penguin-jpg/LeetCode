#include <vector>
using namespace std;

/**
 * 想法: 用 dp table法，dp[i] 代表第 i 天賺到的最大利潤，若第 i-1 天買，第 i 天
 * 賣出能賺錢，則把 dp[i] 更新為 dp[i-1]+prices[i]-prices[i-1]，否則就延續
 * dp[i-1] 就好
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        vector<int> dp(prices.size(), 0);
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 1] + prices[i] - prices[i - 1]);
        }
        return dp[prices.size() - 1];
    }
};