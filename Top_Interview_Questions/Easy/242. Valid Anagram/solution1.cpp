#include <string>
#include <unordered_map>
using namespace std;

/**
 * 想法: 透過 hash map 把 s 的每個字元出現次數存起來，走過一次 t，如果目前 t 的
 * 字元沒有在 hash map 內或次數小於 0，就回傳 false
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        unordered_map<char, int> table;
        for (int i = 0; i < s.length(); i++)
        {
            table[s[i]]++;
        }
        for (int i = 0; i < t.length(); i++)
        {
            if (!table.count(t[i]) || table[t[i]] < 1)
            {
                return false;
            }
            table[t[i]]--;
        }
        return true;
    }
};