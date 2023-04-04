#include <string>
using namespace std;

/**
 * 想法: 優化 solution1 的邏輯，但還是會 TLE
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
            // don't use "*" or use it multiple times
            if (match(s, p, i, j + 1) || (i < s.length() && match(s, p, i + 1, j)))
            {
                return true;
            }
        }
        else if (i < s.length() && (p[j] == s[i] || p[j] == '?'))
        {
            return match(s, p, i + 1, j + 1);
        }
        return false;
    }
};