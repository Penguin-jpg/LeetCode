#include <unordered_map>
using namespace std;

/**
 * 想法: 用 hash map 紀錄出現次數，當發現有出現超過 1 次的就回傳 true
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); i++)
        {
            table[nums[i]]++;
            if (table[nums[i]] > 1)
            {
                return true;
            }
        }
        return false;
    }
};