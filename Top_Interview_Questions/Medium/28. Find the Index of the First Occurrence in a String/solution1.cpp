#include <string>
using namespace std;

/**
 * 想法: 用 two pointers 解，left 指向 window 開頭，right 指向 window 結尾，兩者
 * 必定相隔 needle 的長度，在 right 超出 haystack 前做下列檢查
 * haystack[left~right] 是否等於 needle，是的話救回傳 left，不是的話就繼續移動 window，
 * 若迴圈結束都還沒找到則回傳 -1
 * 時間: O(n*m), n: haystack長度; m: needle長度, 空間: O(1)
 */

class Solution
{
  public:
    int strStr(string haystack, string needle)
    {
        int left = 0, right = needle.length() - 1;
        while (right < haystack.length())
        {
            if (haystack.substr(left, right - left + 1) == needle)
            {
                return left;
            }
            left++;
            right++;
        }
        return -1;
    }
};