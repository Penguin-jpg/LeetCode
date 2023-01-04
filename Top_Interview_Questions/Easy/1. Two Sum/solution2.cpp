#include <vector>
#include <unordered_map>
using namespace std;

/**
 * 想法: 先將 nums 存至 hashmap(因為搜尋只需 O(1))，找尋 target 與目前選定數字
 * 之差是否在 hashmap 內
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); i++)
        {
            table[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int rest = target - nums[i];
            if (table.count(rest) && table[rest] != i)
            {
                return {i, table[rest]};
            }
        }
        return {0, 0};
    }
};