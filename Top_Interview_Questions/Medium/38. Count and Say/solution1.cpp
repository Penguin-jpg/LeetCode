#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

/**
 * 想法: 用 dp table法來解，從 base case n=1 開始，規則是紀錄在遇到另一種數字之
 * 前的數出現的次數，例如："22121"，在 第一個 1 之前出現兩個 2，所以是 two 2's，以此類推，
 * 所以每次都要持續記錄同一個數字次數直到遇見下一種數字為止，再把次數 f 與該
 * 字元 c 組合成 fc 的形式加到 dp[i]
 * 時間: O(n*sum(m_i)), m_i: dp[i-1]的長度, 空間: O(n)
 */

class Solution
{
  public:
    string countAndSay(int n)
    {
        vector<string> dp(n + 1, "");
        dp[1] = "1";
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < dp[i - 1].length(); j++)
            {
                int count = 0;
                while (j + 1 < dp[i - 1].length() && dp[i - 1][j] == dp[i - 1][j + 1]) // group the same digits
                {
                    count++;
                    j++;
                }
                count++; // need to do it one more time since we didn't count the last one, also handle the unique case
                dp[i] += to_string(count) + dp[i - 1][j];
            }
        }
        return dp[n];
    }
};