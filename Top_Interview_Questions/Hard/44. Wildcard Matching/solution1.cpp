#include <string>
using namespace std;

/**
 * 想法: 和 Regular Expression Matching 概念有點像，只是這次的"*"
 * 可以 match 任意長度的序列(不必再被前一個字元所限制)且"."改成了"?"，所以在檢查
 * 時不必看 p[i+1]，直接看 p[i] 即可 (TLE)
 * 時間: C的 m+n 取 n, 空間: 不確定
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
        if (j == p.length())
        {
            return i == s.length();
        }
        else if (p[j] == '*')
        {
            // don't use "*"
            if (match(s, p, i, j + 1))
            {
                return true;
            }
            else
            {
                // use "*" multiple times
                while (i < s.length())
                {
                    i++;
                    if (match(s, p, i, j))
                    {
                        return true;
                    }
                }
            }
        }
        else if (i < s.length() && (p[j] == s[i] || p[j] == '?'))
        {
            return match(s, p, i + 1, j + 1);
        }
        return false;
    }
};