#include <string>
#include <vector>
using namespace std;

/**
 * 參考解答: 用 KMP演算法解
 * 時間: O(n+m), 空間: O(1)
 */

class Solution
{
  public:
    int strStr(string haystack, string needle)
    {
        int i = 0, j = 0;
        vector<int> table = buildTable(needle);
        while (i < haystack.length())
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            if (j == needle.length()) // match
            {
                return i - j;
            }
            if (i < haystack.length() && haystack[i] != needle[j])
            {
                if (j > 0)
                {
                    j = table[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
        return -1;
    }

    vector<int> buildTable(string &pattern)
    {
        vector<int> table(pattern.length(), 0); // table[i] means length of the longest prefix suffix in pattern[0~i]
        int i = 1;
        int length = 0; // length of previous longest prefix suffix
        while (i < pattern.length())
        {
            if (pattern[i] == pattern[length])
            {
                length++;
                table[i] = length;
                i++;
            }
            else
            {
                if (length != 0)
                {
                    length = table[length - 1];
                }
                else
                {
                    table[i] = 0;
                    i++;
                }
            }
        }
        return table;
    }
};