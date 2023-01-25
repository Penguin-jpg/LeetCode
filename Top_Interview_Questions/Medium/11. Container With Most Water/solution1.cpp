#include <vector>
using namespace std;

/**
 * 想法: 用 greedy，暴搜每種組合，找最大 (TLE)
 * 時間: O(n^2), 空間: O(1)
 */

class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int maxValue = 0;
        for (int i = 0; i < height.size() - 1; i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                maxValue = max(maxValue, min(height[i], height[j]) * (j - i));
            }
        }
        return maxValue;
    }
};