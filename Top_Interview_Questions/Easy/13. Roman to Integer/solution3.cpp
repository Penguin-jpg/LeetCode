#include <string>
#include <unordered_map>
using namespace std;

/**
 * 參考解答: 其實規則就是(從左到右讀起來)前面的數字比後面數字小時，就代表要進入特殊規則(順便幫參考的解答加上範圍偵測)
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

            if (i + 1 < length && table[s[i]] < table[s[i + 1]])
            {
                result -= table[s[i]];
            }
            else
            {
                result += table[s[i]];
            }
        }
        return result;
    }
};