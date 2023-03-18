#include <vector>
using namespace std;

/**
 * 參考解答: 這一題的關係式如果要執著於寫成像先前幾個 dp 題目的話會相對麻煩一
 * 點，因為他必須要考慮大小問題，而不是單純的拿或不拿，所以比較好理解的做法應該
 * 是先分別儲存在兩個變數再比大小 (TLE)
 * 時間: O(2^n), 空間: O(n)
 */

class Solution
{
  public:
    int lengthOfLIS(vector<int> &nums)
    {
        return LIS(nums, 0, INT_MIN);
    }

    int LIS(vector<int> &nums, int index, int last)
    {
        if (index >= nums.size())
        {
            return 0;
        }
        // take nums[index] or just ignore it
        int take = 0, notTake = LIS(nums, index + 1, last);
        if (nums[index] > last)
        {
            take = 1 + LIS(nums, index + 1, nums[index]);
        }
        return max(take, notTake);
    }
};