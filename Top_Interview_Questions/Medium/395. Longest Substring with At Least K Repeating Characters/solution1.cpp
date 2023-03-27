#include <string>
using namespace std;

/**
 * 參考解答: 暴力解，找出所有可能
 * 時間: O(n^2), 空間: O(1)
 */

class Solution
{
  public:
    int longestSubstring(string s, int k)
    {
        int maxLength = 0;
        for (int left = 0; left < s.length(); left++)
        {
            int table[26] = {0};
            for (int right = left; right < s.length(); right++)
            {
                table[s[right] - 'a']++;
                if (isValid(table, k))
                {
                    maxLength = max(maxLength, right - left + 1);
                }
            }
        }
        return maxLength;
    }

    bool isValid(int table[26], int k)
    {
        int numUniqueLetters = 0;         // number of unique letters
        int numUniqueLettersAtLeastK = 0; // number of unique letters with at least k length
        for (int i = 0; i < 26; i++)
        {
            numUniqueLetters += table[i] > 0 ? 1 : 0;
            numUniqueLettersAtLeastK += table[i] >= k ? 1 : 0;
        }
        return numUniqueLetters == numUniqueLettersAtLeastK; // all unique letters should have at least k length
    }
};