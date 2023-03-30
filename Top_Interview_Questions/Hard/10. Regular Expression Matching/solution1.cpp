#include <string>
using namespace std;

/**
 * 參考解答: 用遞迴，分成以下幾種情況：
 *      1. 若 j==p.length() -> 回傳 i==s.length() (當 p 走完時，s 應該也要走完了)
 *      2. 若 p[j+1]=='*'，分成兩種情況 ->
 *          2.1. 不使用這個'*'，也就是取 0 次
 *          2.2. 使用這個'*'，看能取幾次
 *      3. 若 p[j+1]!='*'，若 p[j]==s[i] || p[j]=='.' 都可以
 * 時間: O(C的 m+n 取 n), 空間: 不確定
 */

class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        return match(s, p, 0, 0);
    }

    bool match(string &s, string &p, int i, int j)
    {
        if (j == p.length()) // if we are at the end of p, we should also be at the end of s
        {
            return i == s.length();
        }
        if (j + 1 < p.length() && p[j + 1] == '*')
        {
            if (match(s, p, i, j + 2)) // if it is ok to skip '*'
            {
                return true;
            }
            // use '*' and check every possible way to use it
            while (i < s.length() && (p[j] == s[i] || p[j] == '.'))
            {
                i++;
                // use once, twice,...
                if (match(s, p, i, j + 2))
                {
                    return true;
                }
            }
        }
        else if (i < s.length() && (p[j] == s[i] || p[j] == '.')) // if p[j+1]!='*', but it matches with s[i]
        {
            return match(s, p, i + 1, j + 1);
        }
        return false;
    }
};