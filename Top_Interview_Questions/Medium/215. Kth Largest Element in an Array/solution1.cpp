#include <algorithm>
#include <vector>
using namespace std;

/**
 * 想法: 先排序再回傳第 nums.size() - k 個元素
 * 時間: O(nlogn), 空間: O(1)
 */

class Solution
{
  public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};