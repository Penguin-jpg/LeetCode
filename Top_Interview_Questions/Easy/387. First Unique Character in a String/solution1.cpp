#include <string>
#include <unordered_map>
using namespace std;

/**
 * 想法: 透過兩個 hash map 分別儲存次數跟位置，找次數為 1 且位置最小的
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> table;
        unordered_map<char, int> pos;
        int result = -1;
        for (int i = 0; i < s.length(); i++)
        {
            if (pos.count(s[i]) == 0)
            {
                pos[s[i]] = i;
            }
            table[s[i]]++;
        }
        for (auto &it : table)
        {
            if (it.second == 1)
            {
                result = result == -1 ? pos[it.first] : min(result, pos[it.first]);
            }
        }
        return result;
    }
};