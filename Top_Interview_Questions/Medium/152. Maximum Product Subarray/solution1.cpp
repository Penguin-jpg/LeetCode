#include <vector>
using namespace std;

/**
 * 參考解答: 和找 maximum sum subarray 的方式有點像，只是要改成同時記錄最大與最
 * 小值來應付乘上負數的情況，當乘上負數之後最大的值會變為最小的值，而最小的值會
 * 變為最大的值，所以在乘上負數之前要先將兩者交換，才能確保後續判斷正確
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    int maxProduct(vector<int> &nums)
    {
        int result = nums[0], currentMax = nums[0], currentMin = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0) // since multiply a negtaive number will make bigger number become small, and vice versa
            {
                swap(currentMax, currentMin);
            }
            // same process as finding maximum sum subarray, just check if
            // multiply nums[i] will make it bigger (or smaller)
            currentMax = max(nums[i], currentMax * nums[i]);
            currentMin = min(nums[i], currentMin * nums[i]);
            result = max(result, currentMax); // update result
        }
        return result;
    }
};