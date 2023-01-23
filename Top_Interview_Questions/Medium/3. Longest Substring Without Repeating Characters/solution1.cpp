#include <string>
#include <unordered_set>
using namespace std;

/**
 * 想法: 從第一個字元開始，將出現過的字存在一個 set，當遇到重複字時更新最大長
 * 度，並從原本起始點的下一個 index 開始找
 * 時間: O(n^2), 空間: O(n)
 */

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> chars;
        int start = 0;
        int currentLength = 0;
        int maxLength = 0;
        for (int i = start; i < s.length();)
        {
            if (chars.count(s[i]))
            {
                start++;
                i = start;
                maxLength = max(currentLength, maxLength);
                currentLength = 0;
                chars.clear();
                continue;
            }
            chars.insert(s[i]);
            currentLength++;
            i++;
        }
        return max(currentLength, maxLength);
    }
};