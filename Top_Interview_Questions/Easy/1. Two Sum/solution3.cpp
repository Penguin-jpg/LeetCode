#include <vector>
#include <unordered_map>
using namespace std;

/**
 * 參考解答: 沒想到 hashmap 的解可以一邊搜尋一邊建立table，可以少一個 for 迴圈
 */

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); i++)
        {
            int rest = target - nums[i];
            if (table.count(rest))
            {
                return {i, table[rest]};
            }
            else
            {
                table[nums[i]] = i;
            }
        }
        return {0, 0};
    }
};