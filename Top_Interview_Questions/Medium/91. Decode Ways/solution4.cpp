#include <string>
#include <vector>
using namespace std;

/**
 * 參考解答: 用 dp table法來解
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int numDecodings(string s)
    {
        vector<int> dp(s.length() + 1, 0);
        dp[s.length()] = 1;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] != '0')
            {
                dp[i] += dp[i + 1];
            }
            if (i + 1 < s.length() && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')))
            {
                dp[i] += dp[i + 2];
            }
        }
        return dp[0];
    }
};