#include <string>
#include <vector>
using namespace std;

/**
 * 參考解答: 用 dp table法，將遞迴的 memo 過程轉變成 for loop，dp[i][j] 代表
 * s[0..i) 是否 match p[0..j)
 * 時間: O(m*n), 空間: O(m*n)
 */

class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1, false));
        // since we bottom-up recursion, we use bottom-up for loop
        // (you can change it to top-down if you want)
        dp[s.length()][p.length()] = true; // base case
        for (int i = s.length(); i >= 0; i--)
        {
            for (int j = p.length() - 1; j >= 0; j--)
            {
                if (j + 1 < p.length() && p[j + 1] == '*')
                {
                    dp[i][j] = dp[i][j + 2] || (i < s.length() && (p[j] == s[i] || p[j] == '.') && dp[i + 1][j]);
                }
                else
                {
                    dp[i][j] = i < s.length() && (p[j] == s[i] || p[j] == '.') && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};