#include <algorithm>
#include <vector>
using namespace std;

/**
 * 想法: 先排序在找出與後方數字不同的數
 * 時間: O(nlogn), 空間: O(1)
 */

class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        // check every two number
        for (int i = 1; i < nums.size(); i += 2)
        {
            if (nums[i - 1] != nums[i])
            {
                return nums[i - 1];
            }
        }
        // if result can't be found by for loop, means result is the last number
        return nums[nums.size() - 1];
    }
};