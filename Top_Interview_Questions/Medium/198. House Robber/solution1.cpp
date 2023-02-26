#include <vector>
using namespace std;

/**
 * 參考解答: 小偷在第 i 間房子的時候有兩種選擇，偷或者不偷，如果不偷，則目前的總
 * 額就是先前的總額，如果要偷，因為不能連著偷，所以總額變成第 i-2 間前所得總額加
 * 上第 i 間偷到的，因此我們可以歸納出關係式為：max(rob(i-1), nums[i]+rob(i-2))
 * (單純用遞迴會超時，但這樣能更容易觀察到關係式，有助於 dp 的思考)
 * 時間: O(2^n), 空間: O(n)
 */

class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        return robMax(nums, nums.size() - 1);
    }

    int robMax(vector<int> &nums, int i)
    {
        if (i < 0)
        {
            return 0;
        }
        return max(robMax(nums, i - 1), nums[i] + robMax(nums, i - 2));
    }
};
