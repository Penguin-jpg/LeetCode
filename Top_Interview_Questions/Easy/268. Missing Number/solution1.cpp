#include <vector>
using namespace std;

/**
 * 想法: 先算等差級數，再扣掉 nums 總和，差值即為缺少的數
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    int missingNumber(vector<int> &nums)
    {
        int totalSum = (0 + nums.size()) * (nums.size() + 1) / 2; // 0+1+2+...+n
        int currentSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            currentSum += nums[i];
        }
        int diff = totalSum - currentSum;
        return diff == 0 ? 0 : diff;
    }
};