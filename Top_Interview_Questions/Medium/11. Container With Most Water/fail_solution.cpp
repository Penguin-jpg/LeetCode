#include <cmath>
#include <vector>
using namespace std;

/**
 * 想法: 用 two pointers，left 記錄最大的左邊高度，right 記錄最大的右邊高度，如
 * 果 left<right，就將 left 移到 right 右邊，就將 right，每次做完後都將 right 往右看會不會更大
 * 時間: O(n), 空間: O(1)
 * 失敗原因: 只考慮到高度，沒考慮到寬度
 */

class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = 1, maxValue = 0;
        while (right < height.size())
        {
            maxValue = max(maxValue, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right])
            {
                left = right;
            }
            right++;
        }
        return maxValue;
    }
};