#include <unordered_map>
#include <vector>
using namespace std;
/**
 * 想法: 用 hash map 將出現的次數記起來，再去找出現次數超過一半的
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
        int half = nums.size() / 2;
        unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); i++)
        {
            table[nums[i]]++;
        }
        for (auto &it : table)
        {
            if (it.second > half)
            {
                return it.first;
            }
        }
        return nums[0];
    }
};