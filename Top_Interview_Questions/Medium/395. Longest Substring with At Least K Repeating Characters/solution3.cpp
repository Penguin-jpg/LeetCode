#include <string>
#include <unordered_map>
using namespace std;

/**
 * 參考解答: 用 sliding window 解，先找出每個字元對應的次數，設 map 大小為m，
 * 1 ~ m 是所有可能的 unique 字元數，對每種可能我們都要做一次 sliding window，
 * 並用兩個變數紀錄目前的 unique 字元數以及目前出現次數至少 k 次的字元數，如果目
 * 前的 unique 字元數 <= 本次應該出現的 unique 字元數，則繼續擴增 window，若已
 * 經超過該數值了，則縮減 window，最後若目前的 unique 字元數及出現次數至少 k 次
 * 的字元數都等於本次應該出現的 unique 字元數，代表這是個 valid 的 substring
 * 時間: O(m*n), m: unique 字元數, 空間: O(m)
 */

class Solution
{
  public:
    int longestSubstring(string s, int k)
    {
        int maxLength = 0;
        unordered_map<int, int> table;
        for (int i = 0; i < s.length(); i++)
        {
            table[s[i] - 'a']++;
        }
        // numUniqueLetters: number of unique letters should be found in this sliding window
        for (int numUniqueLetters = 1; numUniqueLetters <= table.size(); numUniqueLetters++)
        {
            int left = 0, right = 0;          // left and right of window
            int numCurrentUniqueLetters = 0;  // number of current found unique letters
            int numUniqueLettersAtLeastK = 0; // number of current found unique letters with at least k length
            int frequencies[26] = {0};        // frequency of each letter
            while (right < s.length())
            {
                // we need to expand the window until we meet numUniqueLetters
                // after meeting numUniqueLetters, we can still try to expand it
                // since there might be the same letters behind
                if (numCurrentUniqueLetters <= numUniqueLetters)
                {
                    int letter = s[right] - 'a';
                    frequencies[letter]++;
                    // if this is a new letter
                    numCurrentUniqueLetters += frequencies[letter] == 1 ? 1 : 0;
                    // if this letter with at least k length (we only record
                    // once so just check if it is equal to k)
                    numUniqueLettersAtLeastK += frequencies[letter] == k ? 1 : 0;
                    right++; // expand window
                }
                else // numCurrentUniqueLetters exceeds numUniqueLetters, we need to shrink the window
                {
                    int letter = s[left] - 'a';
                    frequencies[letter]--;
                    // if this is a new letter
                    numCurrentUniqueLetters -= frequencies[letter] == 0 ? 1 : 0;
                    numUniqueLettersAtLeastK -= frequencies[letter] == k - 1 ? 1 : 0;
                    left++; // shrink the window
                }
                // if we found valid substring in current window, update maxLength
                if (numCurrentUniqueLetters == numUniqueLetters && numUniqueLettersAtLeastK == numUniqueLetters)
                {
                    maxLength = max(maxLength, right - left);
                }
            }
        }
        return maxLength;
    }
};