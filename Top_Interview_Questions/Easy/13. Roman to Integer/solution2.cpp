#include <string>
#include <unordered_map>
using namespace std;

/**
 * 想法: 基本上同 solution1，但透過第二個 hashmap 簡化判斷程式碼
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    int romanToInt(string s)
    {
        unordered_map<char, int> table{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        unordered_map<string, int> specialTable{{"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}};
        int length = s.length();
        int result = 0;
        for (int i = 0; i < length; i++)
        {
            if (i + 1 < length)
            {
                string sub = s.substr(i, 2);
                if (specialTable.count(sub))
                {
                    result += specialTable[sub];
                    i++;
                    continue;
                }
            }
            result += table[s[i]];
        }
        return result;
    }
};