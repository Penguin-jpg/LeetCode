#include <string>
#include <unordered_map>
using namespace std;

/**
 * 想法: 用 hashmap 建 table，並按照規則做
 *      1. 若目前為 I -> 檢查後面是否為 V(4) 或 X(9)
 *      2. 若目前為 X -> 檢查後面是否為 L(40) 或 C(90)
 *      3. 若目前為 C -> 檢查後面是否為 D(400) 或 M(900)
 *      4. 其餘照表格填
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    int romanToInt(string s)
    {
        unordered_map<char, int> table{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int length = s.length();
        int result = 0;
        for (int i = 0; i < length; i++)
        {
            if (i + 1 < length)
            {
                string sub = s.substr(i, 2);
                if (sub == "IV")
                {
                    result += 4;
                    i++;
                }
                else if (sub == "IX")
                {
                    result += 9;
                    i++;
                }
                else if (sub == "XL")
                {
                    result += 40;
                    i++;
                }
                else if (sub == "XC")
                {
                    result += 90;
                    i++;
                }
                else if (sub == "CD")
                {
                    result += 400;
                    i++;
                }
                else if (sub == "CM")
                {
                    result += 900;
                    i++;
                }
                else
                {
                    result += table[s[i]];
                }
            }
            else
            {
                result += table[s[i]];
            }
        }
        return result;
    }
};