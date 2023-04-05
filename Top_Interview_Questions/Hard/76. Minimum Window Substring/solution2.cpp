#include <string>
#include <unordered_map>
using namespace std;

/**
 * 參考解答: 可以將 solution1 的邏輯稍加修改(改成原本解答的樣子)，我們並不需要檢
 * 查 s[right] 是否在 table 中，我們只要確定若 table[s[right]]>0 時，就必須
 * 將 remainLength--，s[left] 同理，我們不用檢查是否在 table 內，只要確定若
 * table[s[left]]>0 時，要將 remainLength++。
 * 至於為什麼可以這樣想，可以先假設若 s[right] 原本不在 table 中，也就不在 t 中，他
 * 在 table 中出現的對應次數是多少根本不影響；同理，若假設 s[left] 原本不在 table 中，
 * 就算做了 table[s[left]]++，最多也就是將其還原至 table[s[left]]=0，不可能更
 * 高，所以根本不影響。
 * 最後一項改善是不要每次都取 substr，只要用個變數將 length 為最小值時的起點
 * index 也記錄起來即可。
 * 時間: O(m+n), m: s 長度; n: t 長度, 空間: O(n)
 */

class Solution
{
  public:
    string minWindow(string s, string t)
    {
        int left = 0, start = 0;        // start is the head of min length window
        int remainLength = t.length();  // how many char we still need to reach length of t
        unordered_map<char, int> table; // store char of t and its frequency
        int minLength = -1;
        for (int i = 0; i < t.length(); i++)
        {
            table[t[i]]++;
        }
        for (int right = 0; right < s.length(); right++)
        {
            if (table[s[right]] > 0)
            {
                remainLength--;
            }
            table[s[right]]--;
            while (remainLength == 0) // all chars in t are inside the window
            {
                int length = right - left + 1;
                if (minLength == -1 || length < minLength)
                {
                    start = left;
                    minLength = length;
                }
                table[s[left]]++;
                if (table[s[left]] > 0)
                {
                    remainLength++;
                }
                left++;
            }
        }
        return minLength == -1 ? "" : s.substr(start, minLength);
    }
};