#include <string>
#include <unordered_map>
using namespace std;

/**
 * 想法: 每次用個 for 迴圈決定要取的字數，接下來檢查取出來的數是否在 hash map
 * 內，若不在，代表這種取法不行，最後回傳所有取法的數量 (TLE)
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int numDecodings(string s)
    {
        int counter = 0;
        int length = s.length();
        unordered_map<string, bool> table;
        for (int i = 0; i < 26; i++)
        {
            table[to_string(i + 1)] = true;
        }
        decode(s, 0, counter, table);
        return counter;
    }

    void decode(string &s, int index, int &counter, unordered_map<string, bool> &table)
    {
        if (index >= s.length())
        {
            counter++;
            return;
        }
        for (int i = 1; i <= 2 && index + i <= s.length(); i++)
        {
            string sub = s.substr(index, i);
            if (table.count(sub) == 0)
            {
                return;
            }
            decode(s, index + i, counter, table);
        }
    }
};