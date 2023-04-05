#include <string>
#include <unordered_map>
using namespace std;

/**
 * 想法: 用 sliding window 解，但這次的做法比較特殊，和先前那種單純用一層迴圈內
 * 的判斷進行擴增、縮減的方式有點不同，我們需要在條件完成後，再慢慢縮小，直到不
 * 符合條件為止。
 * 擴增的的條件是 t 中的字還沒全部用完，縮小的條件是當移動 left 後會導致 t 中的
 * 字用不完，這個解法的作者很聰明的用了字串長度當做二重檢查，就不需要每次都跑過
 * 整個 hash map 來確保字都有用完 (C++ 跑會 TLE，Python 不會)
 * (由於我有將部分邏輯修改成比較直覺的方式，想看原本解答的話可以到下面的連結)
 * https://leetcode.com/problems/minimum-window-substring/solutions/226911/python-two-pointer-sliding-window-with-explanation/
 * 時間: O(m+n), m: s 長度; n: t 長度, 空間: O(n)
 */

class Solution
{
  public:
    string minWindow(string s, string t)
    {
        int left = 0;
        int remainLength = t.length();  // how many char we still need to reach length of t
        unordered_map<char, int> table; // store char of t and its frequency
        string result = "";
        for (int i = 0; i < t.length(); i++)
        {
            table[t[i]]++;
        }
        for (int right = 0; right < s.length(); right++)
        {
            if (table.count(s[right]))
            {
                // if we found a char in t (only decrease when it is still bigger than 0)
                remainLength -= table[s[right]] > 0 ? 1 : 0;
                table[s[right]]--;
            }
            while (remainLength == 0) // all chars in t are inside the window
            {
                int length = right - left + 1;
                // only update when result=="" or it is shorter than current length
                if (result == "" || length < result.length())
                {
                    result = s.substr(left, length);
                }
                if (table.count(s[left])) // check if shrinking affects result
                {
                    table[s[left]]++;
                    // if table[s[left]]>0, means that some char in t will not be included if we shrink the window
                    remainLength += table[s[left]] > 0 ? 1 : 0;
                }
                left++;
            }
        }
        return result;
    }
};