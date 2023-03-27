#include <string>
using namespace std;

/**
 * 參考解答: divide and conquer，從第一個長度不到 k 的字元切開，分成左右，再對左
 * 邊及右邊繼續切，比較左右兩邊字串長度誰大，圖解可以看下列網址：
 * https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/editorial/
 * 時間: O(n^2), 空間: O(n)
 */

class Solution
{
  public:
    int longestSubstring(string s, int k)
    {
        return getMaxLength(s, 0, s.length(), k);
    }

    int getMaxLength(string &s, int left, int right, int k)
    {
        if (right - left < k) // length is less than k
        {
            return 0;
        }
        int table[26] = {0};
        for (int i = left; i < right; i++)
        {
            table[s[i] - 'a']++;
        }
        for (int split = left; split < right; split++) // do not include right
        {
            if (table[s[split] - 'a'] < k) // find the split point
            {
                return max(getMaxLength(s, left, split, k), getMaxLength(s, split + 1, right, k));
            }
        }
        return right - left;
    }
};