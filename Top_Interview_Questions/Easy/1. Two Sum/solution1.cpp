#include <vector>
using namespace std;

/**
 * 想法: 因為必存在一組解，所以兩兩搭配一定能找出答案
 * 時間: O(n^2), 空間: O(1)
 */

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int rest = target - nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] == rest)
                {
                    return {i, j};
                }
            }
        }
        return {0, 0};
    }
};