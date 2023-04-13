#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 想法: 將所有點之間的斜率找出，最多共同斜率的就是答案 (失敗，少判斷了垂直線(斜
 * 率無窮大)的情況)
 * 時間: O(n^2), 空間: O(n)
 */

class Solution
{
  public:
    int maxPoints(vector<vector<int>> &points)
    {
        int result = 0;
        for (int i = 0; i < points.size(); i++)
        {
            unordered_map<double, int> slopes; // store calculated slopes (only for this time)
            int currentMax = 0;                // store the current max
            for (int j = i + 1; j < points.size(); j++)
            {
                // slope = dy/dx
                // use double for better precision
                double slope = double(points[j][1] - points[i][1]) / double(points[j][0] - points[i][0]);
                slopes[slope]++;
            }
            for (auto &it : slopes)
            {
                if (it.second > currentMax)
                {
                    currentMax = it.second;
                }
            }
            currentMax++; // when calculating slopes, we didn't include points[i], so we need to add it back
            result = max(result, currentMax);
        }
        return result;
    }
};