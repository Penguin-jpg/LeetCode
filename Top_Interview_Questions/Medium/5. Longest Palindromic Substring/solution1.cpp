#include <string>
using namespace std;

/**
 * 參考解答: 用 DP 解，用一個 n*n 的陣列 dp，dp[i][j] 紀錄 s[i] ~ s[j] 是否為回
 * 文，當發生 s[i]==s[j] 的情況，我們就要檢查其是否是回文，而是回文的話會有兩種可能：
 *      1. 該字串長度為 2 (j-i=1)
 *      2. i ~ j 之間的子字串是回文 (dp[i+1][j-1]=true)
 * 時間: O(n^2), 空間: O(n^2)
 */

class Solution
{
  public:
    string longestPalindrome(string s)
    {
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        string result = "";
        result += s[0]; // to handle length 1 strings and non-palindrome strings
        for (int i = 0; i < s.length(); i++)
        {
            dp[i][i] = true; // every single character is palindrome substring
        }
        // because our checking method depends on the substring i+1 ~ j-1, we
        // need to do it from bottom
        for (int i = s.length() - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < s.length(); j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i == 1 || dp[i + 1][j - 1])
                    {
                        dp[i][j] = true;
                        result = result.length() < j - i + 1 ? s.substr(i, j - i + 1) : result;
                    }
                }
            }
        }
        return result;
    }
};