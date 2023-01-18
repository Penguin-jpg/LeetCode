#include <string>
using namespace std;

/**
 * 參考解答: 由於只有 26 個小寫英文字母，可以直接用陣列來記錄
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        int letters[26] = {0};
        for (int i = 0; i < s.length(); i++)
        {
            letters[s[i] - 'a']++;
            letters[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (letters[i] < 0)
            {
                return false;
            }
        }
        return true;
    }
};