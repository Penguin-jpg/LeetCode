#include <string>
#include <vector>
using namespace std;

/**
 * 想法: 改用 dp table法來完成，為了符合先前的邏輯，所以會繼續使用 bottom-up 的
 * 方式，dp[i][j] 代表 s[0..i) 是否 match p[0..j)
 * 時間: O(m*n), 空間: O(m*n)
 */

class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[m][n] = true;
        for (int i = m; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (p[j] == '*')
                {
                    dp[i][j] = dp[i][j + 1] || (i < m && dp[i + 1][j]);
                }
                else
                {
                    dp[i][j] = i < m && (p[j] == s[i] || p[j] == '?') && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};