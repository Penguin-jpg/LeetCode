#include <vector>
using namespace std;

/**
 * 想法: 用一層迴圈，每次檢查加上現在的值是否比直接從現在的值開始更好，若目前的
 * 和小於 0，則從該數的下一個數開始；若取得更大的數，就更新最大值
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0, maxSum = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            sum = max(nums[i], nums[i] + sum);
            maxSum = max(sum, maxSum);
            sum = sum < 0 ? 0 : sum;
        }
        return maxSum;
    }
};