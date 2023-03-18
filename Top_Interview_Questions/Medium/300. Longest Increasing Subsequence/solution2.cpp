#include <vector>
using namespace std;

/**
 * 參考解答: 從 solution1 可以看出會有許多的重複計算，我們可以透過 dp memo法來紀
 * 錄第 i 個 index能產生的最大長度，若目前的 nums[index]>nums[i]，就可以直接帶入
 * 1+memo[i] 來節省計算 (存 index 主要是因為數字可重複)
 * 時間: O(n^2), 空間: O(n)
 */

class Solution
{
  public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> memo(nums.size() + 1, -1);
        return LIS(nums, 0, -1, memo);
    }

    int LIS(vector<int> &nums, int index, int lastIndex, vector<int> &memo)
    {
        if (index >= nums.size())
        {
            return 0;
        }
        else if (memo[lastIndex + 1] != -1)
        {
            return memo[lastIndex + 1];
        }
        int take = 0, notTake = LIS(nums, index + 1, lastIndex, memo);
        if (lastIndex == -1 || nums[index] > nums[lastIndex])
        {
            take = 1 + LIS(nums, index + 1, index, memo);
        }
        memo[lastIndex + 1] = max(take, notTake);
        return memo[lastIndex + 1];
    }
};