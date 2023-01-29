#include <vector>
using namespace std;

/**
 * 參考解答: 由於陣列旋轉過，所以不能直接使用一般的 binary search，必須分成以下兩種情況來考慮：
 *          1. target 和 nums[mid] 在同一邊 -> 直接對這一邊做 binary search
 *          2. target 和 nums[mid] 在不同邊 -> 將比較對象改為 -INF 或 INF
 * 詳細解釋可看這個連結:
 * https://leetcode.com/problems/search-in-rotated-sorted-array/solutions/154836/the-inf-and-inf-method-but-with-a-better-explanation-for-dummies-like-me/
 */

class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {
        int pivot = nums[0], left = 0, right = nums.size() - 1;
        double comparator = 0.0; // used to check if nums[mid] and target are on the same side
        while (left <= right)
        {
            int mid = (left + right) / 2;
            // 1. (target < pivot && nums[mid] < pivot) || (target > pivot &&
            //    nums[mid] > pivot) -> both are on the other side
            // 2. else -> target and nums[mid] are on different sides
            if (((target < pivot) && (nums[mid] < pivot)) || ((target >= pivot) && (nums[mid] >= pivot)))
            {
                // we can safely use nums[mid] as comparator
                comparator = nums[mid];
            }
            else
            {
                // it means that target on the right side and nums[mid] on the
                // left side. So we fake that all left hand side are -INF, then
                // we can just use regular binary search on the right side
                if (target < pivot)
                {
                    comparator = -INFINITY;
                }
                else // it means that target on the left side and nums[mid] on the right side
                {
                    comparator = INFINITY;
                }
            }
            if (target == comparator) // found target (only happen when comparator=nums[mid])
            {
                return mid;
            }
            else if (target > comparator)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};