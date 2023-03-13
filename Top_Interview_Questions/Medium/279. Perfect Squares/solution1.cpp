#include <cmath>
#include <vector>
using namespace std;

/**
 * 參考解答: 用 dp table法解，dp[i] 代表 i 所需要的最少 perfect square 相加次
 * 數，觀察可看出關係式：dp[i] = min(dp[i-j]+1, dp[i]) (j<=i)，最小值要不是扣掉 j
 * 後的最小值再加 1，要不就是目前的最小值，詳細解釋可看以下連結：
 * https://leetcode.com/problems/perfect-squares/solutions/1520447/c-dp-easy-to-understand/
 * 時間: O(n*sqrt(n)), 空間: O(n)
 */

class Solution
{
  public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0; // base case
        int end = sqrt(n);
        for (int i = 1; i <= end; i++)
        {
            int square = i * i; // current perfect square we consider
            for (int j = square; j <= n; j++)
            {
                dp[j] = min(dp[j - square] + 1, dp[j]);
            }
        }
        return dp[n];
    }
};