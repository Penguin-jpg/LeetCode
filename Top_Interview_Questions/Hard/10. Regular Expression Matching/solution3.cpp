#include <string>
#include <vector>
using namespace std;

/**
 * 參考解答: 可以觀察到其實很多的計算都是重複的，所以應該要使用 dp，這邊用 dp
 * memo 法，dp[i][j] 代表 s[0..i) 是否 match p[0..j)
 * 時間: O(m*n), 空間: O(m*n)
 */

class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        vector<vector<int>> memo(s.length() + 1, vector<int>(p.length() + 1, -1));
        return match(s, p, 0, 0, memo);
    }

    bool match(string &s, string &p, int i, int j, vector<vector<int>> &memo)
    {
        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }
        if (j == p.length()) // if we are at the end of p, we should also be at the end of s
        {
            memo[i][j] = i == s.length();
            return memo[i][j];
        }
        if (j + 1 < p.length() && p[j + 1] == '*')
        {
            // don't use or use multiple times
            if (match(s, p, i, j + 2, memo) ||
                (i < s.length() && (p[j] == s[i] || p[j] == '.') && match(s, p, i + 1, j, memo)))
            {
                memo[i][j] = 1;
                return memo[i][j];
            }
        }
        else if (i < s.length() && (p[j] == s[i] || p[j] == '.')) // if p[j+1]!='*', but it matches with s[i]
        {
            memo[i][j] = match(s, p, i + 1, j + 1, memo);
            return memo[i][j];
        }
        memo[i][j] = 0;
        return memo[i][j];
    }
};