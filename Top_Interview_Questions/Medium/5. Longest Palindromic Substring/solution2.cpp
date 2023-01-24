#include <string>
using namespace std;

/**
 * 參考解答: 用 two pointers 解，可以將回文分成兩種:
 *      1. 奇數型回文: 有一個正中心，其他左右兩邊字元兩兩對稱 e.g. "cbabc"
 *      2. 偶數型回文: 整個回文都是兩兩對稱的字元構成 e.g. "cbaabc"
 * 檢查這兩種回文的情況，找出長度最大的就是答案
 * 時間: O(n^2), 空間: O(1)
 */

class Solution
{
  public:
    string longestPalindrome(string s)
    {
        int start = 0, maxLength = 0, size = s.length();
        // check odd length palindrome
        for (int i = 0; i < size; i++)
        {
            int left = i, right = i;
            while (left >= 0 && right < size && s[left] == s[right])
            {
                left--;
                right++;
            }
            // since we will do one extra expanding before the checking ends, so
            // the actual range of substring is [left+1, right-1], and the
            // length of range is (right-1)-(left+1)+1=right-left-1
            if (maxLength < right - left - 1)
            {
                maxLength = right - left - 1;
                start = left + 1;
            }
        }
        // check even length palindrome
        for (int i = 0; i < size; i++)
        {
            int left = i, right = i + 1;
            while (left >= 0 && right < size && s[left] == s[right])
            {
                left--;
                right++;
            }
            if (maxLength < right - left - 1)
            {
                maxLength = right - left - 1;
                start = left + 1;
            }
        }
        return s.substr(start, maxLength);
    };
};