#include <vector>
using namespace std;

/**
 * 想法: 暴力解
 * 時間: O(n^2), 空間: O(1)
 */

class Solution
{
  public:
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> results(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] < nums[i])
                {
                    results[i]++;
                }
            }
        }
        return results;
    }
};