#include <string>
#include <unordered_map>
using namespace std;

/**
 * 想法: 每次用個 for 迴圈決定要取的字數，接下來檢查取出來的數是否在 hash map
 * 內，若不在，代表這種取法不行，最後回傳所有取法的數量，額外用 memo 紀錄目前切
 * 法是否可以成功，避免重複計算
 * 時間: O(), 空間: O(n)
 */

class Solution
{
  public:
    int numDecodings(string s)
    {
        int length = s.length();
        unordered_map<string, int> memo;
        unordered_map<string, bool> table;
        for (int i = 0; i < 26; i++)
        {
            table[to_string(i + 1)] = true;
        }
        return decode(s, 0, length, table, memo);
    }

    int decode(string s, int index, int &length, unordered_map<string, bool> &table, unordered_map<string, int> &memo)
    {
        if (index >= length)
        {
            return 1;
        }
        else if (memo[s])
        {
            return memo[s];
        }
        for (int i = 1; i <= 2 && i <= s.length(); i++)
        {
            string sub = s.substr(0, i);
            if (table.count(sub) == 0)
            {
                return memo[s];
            }
            memo[s] += decode(s.substr(i), index + i, length, table, memo);
        }
        return memo[s];
    }
};