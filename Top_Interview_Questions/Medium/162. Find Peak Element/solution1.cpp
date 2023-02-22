#include <vector>
using namespace std;

/**
 * 想法: 搜完整個陣列 (雖然不會 TLE，但不符合題目要的 O(logn))
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    int findPeakElement(vector<int> &nums)
    {
        if (nums.size() == 1 || nums[0] > nums[1])
        {
            return 0;
        }
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (i + 1 < nums.size() && nums[i - 1] < nums[i] && nums[i + 1] < nums[i])
            {
                return i;
            }
        }
        return nums.size() - 1;
    }
};