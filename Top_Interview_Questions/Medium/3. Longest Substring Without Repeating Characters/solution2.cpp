#include <string>
#include <unordered_map>
using namespace std;

/**
 * 參考解答: 用 sliding window
 * 來解，詳細解說請看以下連結
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/solutions/347818/python3-sliding-window-o-n-with-explanation/
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> seen; // store char and the last index we saw it
        int left = 0;                  // start of the window
        int maxLength = 0;
        for (int right = 0; right < s.length(); right++)
        {
            // if we haven't seen s[right], just incrase the window size
            if (!seen.count(s[right]))
            {
                maxLength = max(maxLength, right - left + 1);
            }
            else // two cases for seen s[right]
            {
                // case 1: s[right] is not inside the current window (the
                // repeated char won't affect since it is outside the window),
                // then just increase the window size
                if (seen[s[right]] < left)
                {
                    maxLength = max(maxLength, right - left + 1);
                }
                // case 2: s[right] is inside current window (substring now
                // reaches its longest length), we have to move left to the
                // index right after the repated char
                else
                {
                    left = seen[s[right]] + 1;
                }
            }
            seen[s[right]] = right; // update the last seen index of s[right]
        }
        return maxLength;
    }
};