#include <vector>
using namespace std;

/**
 * 參考解答: 由於要從中找到最小和最大的 index，在找到 nums[mid]==target 後不能停
 * 下來，對 lower bound 來說，應該要繼續從 right=mid-1 的地方繼續找有沒有更後面
 * 的，而對 upper bound 來說要繼續從 left=mid-1 的地方繼續找有沒有更前面的
 * 時間: O(logn), 空間: O(1)
 */

class Solution
{
  public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int lowerBound = -1, upperBound = -1;
        while (left <= right) // find the lower bound
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                lowerBound = mid;
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        if (lowerBound == -1)
        {
            return {-1, -1};
        }
        left = 0;
        right = nums.size() - 1;
        while (left <= right) // find the upper bound
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                upperBound = mid;
                left = mid + 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return {lowerBound, upperBound};
    }
};