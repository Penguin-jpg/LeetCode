#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 參考解答: 在 fail_solution 加入斜率無窮大的判斷
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
                int dy = points[j][1] - points[i][1], dx = points[j][0] - points[i][0];
                if (dx == 0) // infinite slope
                {
                    slopes[INT_MAX]++;
                }
                else
                {
                    slopes[double(dy) / double(dx)]++;
                }
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