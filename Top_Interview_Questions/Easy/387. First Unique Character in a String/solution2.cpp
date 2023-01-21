#include <string>
#include <unordered_map>
using namespace std;

/**
 * 參考解答: solution1優化版，透過 pair 同時儲存位置和次數
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int firstUniqChar(string s)
    {
        unordered_map<char, pair<int, int>> table;
        int result = -1;
        for (int i = 0; i < s.length(); i++)
        {
            // don't need to worry about if this is the first position of s[i] because if it only appears
            // once then there won't be a second position
            table[s[i]].first = i;
            table[s[i]].second++;
        }
        for (auto &it : table)
        {
            if (it.second.second == 1)
            {
                result = result == -1 ? it.second.first : min(result, it.second.first);
            }
        }
        return result;
    }
};