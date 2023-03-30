#include <string>
using namespace std;

/**
 * 參考解答: 概念和 solution1 相同，但是可以更加精簡邏輯以達到更好的 runtime
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
            // don't use or use multiple times
            if (match(s, p, i, j + 2) || (i < s.length() && (p[j] == s[i] || p[j] == '.') && match(s, p, i + 1, j)))
            {
                return true;
            }
        }
        else if (i < s.length() && (p[j] == s[i] || p[j] == '.')) // if p[j+1]!='*', but it matches with s[i]
        {
            return match(s, p, i + 1, j + 1);
        }
        return false;
    }
};