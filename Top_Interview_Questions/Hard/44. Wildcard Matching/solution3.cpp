#include <string>
#include <vector>
using namespace std;

/**
 * 想法: 由於過多的重複計算導致 TLE，所以我們透過 dp memo法來避免重複計
 * 算，memo[i][j] 代表 s[0..i) 是否 match p[0..j)
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
        if (j == p.length())
        {
            memo[i][j] = i == s.length();
            return memo[i][j];
        }
        else if (p[j] == '*')
        {
            // don't use "*" or use it multiple times
            if (match(s, p, i, j + 1, memo) || (i < s.length() && match(s, p, i + 1, j, memo)))
            {
                memo[i][j] = true;
                return memo[i][j];
            }
        }
        else if (i < s.length() && (p[j] == s[i] || p[j] == '?'))
        {
            memo[i][j] = match(s, p, i + 1, j + 1, memo);
            return memo[i][j];
        }
        memo[i][j] = false;
        return memo[i][j];
    }
};