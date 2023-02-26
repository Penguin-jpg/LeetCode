#include <vector>
using namespace std;

/**
 * 參考解答: 用 dp memo法
 * 時間: O(n), 空間: O(n)
 */

class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        vector<int> memo(nums.size(), -1);
        return robMax(nums, 0, memo);
    }

    int robMax(vector<int> &nums, int i, vector<int> &memo)
    {
        if (i >= nums.size())
        {
            return 0;
        }
        else if (memo[i] != -1)
        {
            return memo[i];
        }
        // steal next house or steal this and the next of next house
        memo[i] = max(robMax(nums, i + 1, memo), nums[i] + robMax(nums, i + 2, memo));
        return memo[i];
    }
};
