#include <vector>
using namespace std;

/**
 * 想法: 把每種可能的面積組合找出，再找最大值 (TLE)
 * 時間: O(n^2), 空間: O(1)
 */

class Solution
{
  public:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            int width = 1, height = heights[i];
            for (int j = i; j < heights.size(); j++)
            {
                if (heights[j] == 0) // if we found zero height rectangle along the way, restart after this rectangle
                {
                    width = 1;
                    continue;
                }
                height = min(height, heights[j]); // keep updating height to match the smallest height
                maxArea = max(maxArea, width * height);
                width++;
            }
        }
        return maxArea;
    }
};