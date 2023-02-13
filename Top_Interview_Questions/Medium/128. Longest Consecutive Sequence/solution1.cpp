#include <algorithm>
#include <vector>
using namespace std;

/**
 * 想法: 先排序，再找連續子序列 (不符合題目要求的 O(n) 複雜度，但能過)
 * 時間: O(nlogn), 空間: O(1)
 */

class Solution
{
  public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int maxLength = 1, currentLength = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            int diff = nums[i] - nums[i - 1];
            if (diff == 1) // consecutive element
            {
                currentLength++;
                maxLength = max(maxLength, currentLength);
            }
            else if (diff == 0) // repeating element
            {
                continue;
            }
            else // non-consecutive element
            {
                currentLength = 1;
            }
        }
        return maxLength;
    }
};