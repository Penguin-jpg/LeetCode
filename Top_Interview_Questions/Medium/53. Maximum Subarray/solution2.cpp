#include <vector>
using namespace std;

/**
 * 參考解答: 優化版的solution1，其實不需要檢查 sum 是否小於 0，直接找純用該數
 * 還是加上先前最大值上比較大就好，該演算法稱為 Kadane's Algorithm
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
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};