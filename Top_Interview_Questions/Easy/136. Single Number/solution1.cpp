#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 想法: 用 hash map 把出現次數存起來，最後回傳只出現一次的
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> table;
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            table[nums[i]]++;
        }
        for (auto &it : table)
        {
            if (it.second == 1)
            {
                result = it.first;
                break;
            }
        }
        return result;
    }
};