#include <vector>
using namespace std;

/**
 * 參考解答: 如果不太習慣用單變數紀錄目前最大最小值的話，可以改用陣列 (dp table法)
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int maxProduct(vector<int> &nums)
    {
        int result = nums[0];
        vector<int> currentMax(nums.size(), nums[0]);
        vector<int> currentMin(nums.size(), nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0) // since multiply a negtaive number will make bigger number become small, and vice versa
            {
                swap(currentMax[i - 1], currentMin[i - 1]);
            }
            // same process as finding maximum sum subarray, just check if
            // multiply nums[i] will make it bigger (or smaller)
            currentMax[i] = max(nums[i], currentMax[i - 1] * nums[i]);
            currentMin[i] = min(nums[i], currentMin[i - 1] * nums[i]);
            result = max(result, currentMax[i]); // update result
        }
        return result;
    }
};