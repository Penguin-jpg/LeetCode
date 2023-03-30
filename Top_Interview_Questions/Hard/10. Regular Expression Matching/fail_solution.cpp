#include <string>
using namespace std;

/**
 * 想法: 將整體拆分成以下幾種情況：
 *       1. 下一個字元是'*'
 *          1.1: 本次字元是'.' -> 可搭配任意字元 -> 用 s[i] match
 *          1.2: 本次字元是字母 -> 看能消掉幾個 s 內的字元
 *       2. 下一個字元不是'*'
 *          2.1: 本次字元是'.' -> 抵銷掉這次的 s[i]
 *          2.2: 本次字元是字母且和 s[i] 相同 -> 抵掉這次的 s[i]
 *          2.3: 本次字元是字母且和 s[i] 不同 -> 回傳 false
 * 如果最後都能成功配完就回傳 true0
 * (失敗: 太多 edge case 沒考慮到)
 */

class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        int i = 0, j = 0;
        while (i < s.length() && j < p.length())
        {
            if (j + 1 < p.length() && p[j + 1] == '*') // if the next char is '*'
            {
                char preceding = 0;
                if (p[j] == '.') // use any char
                {
                    preceding = s[i]; // since we need to match s[i], just assign s[i] to it
                }
                else // use preceding char
                {
                    preceding = p[j];
                }
                while (s[i] == preceding)
                {
                    i++;
                }
                j += 2;
            }
            else // if the next char is not '*'
            {
                if (p[j] == '.' || p[j] == s[i]) // matches any char or p[j]==s[i]
                {
                    i++;
                }
                else
                {
                    return false;
                }
                j++;
            }
        }
        return true;
    }
};