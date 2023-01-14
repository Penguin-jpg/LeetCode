#include <algorithm>
#include <vector>
using namespace std;
/**
 * 參考解答: 先排序，排完之後眾數會在 nums[nums.size()/2]
 * 時間: O(nlogn), 空間: O(1)
 */

class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};