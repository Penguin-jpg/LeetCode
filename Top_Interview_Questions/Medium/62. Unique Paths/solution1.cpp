#include <vector>
using namespace std;

/**
 * 想法: 用 dp table法來做 (因為 pair 不能當 key 所以不能用 memo)，base case 為
 * dp[0][i], dp[i][0] 都是 1 (邊界只能往右或往下), 關係式為
 * dp[i][j] = dp[i-1][j] + dp[i][j-1]
 * 時間: O(m*n), 空間: O(m*n)
 */

class Solution
{
  public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};