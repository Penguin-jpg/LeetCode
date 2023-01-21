#include <string>
#include <unordered_map>
using namespace std;

/**
 * 參考解答: 只用 hash map 紀錄字元及次數，但需要跑第二次字串迴圈找位置，不適合用在字串很長的時候
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> table;
        for (int i = 0; i < s.length(); i++)
        {
            table[s[i]]++;
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (table[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};