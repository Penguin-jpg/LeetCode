#include <vector>
using namespace std;

/**
 * 想法: 暴力解，三層迴圈 (TLE)
 * 時間: O(n^3), 空間: O(1)
 */

class Solution
{
  public:
    bool increasingTriplet(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 2; i++)
        {
            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    if (nums[i] < nums[j] && nums[j] < nums[k])
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};