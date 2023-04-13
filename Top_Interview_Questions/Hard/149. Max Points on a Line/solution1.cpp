#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 想法: 和前一種寫法概念一樣，不過改成使用分數的形式來記錄，就可以避免浮點數難以比
 * 對的情況，並找 GCD 化到最簡，參考了下列連結的 key 格式：
 * https://leetcode.com/problems/max-points-on-a-line/solutions/47124/c-slope-counter/
 * (也可以自己寫一個 pair<int,int> 的 hash)
 * 時間: O(n^3), 空間: O(n)
 */

class Solution
{
  public:
    int maxPoints(vector<vector<int>> &points)
    {
        int result = 0;
        for (int i = 0; i < points.size(); i++)
        {
            unordered_map<string, int> slopes;
            int currentMax = 0;
            for (int j = i + 1; j < points.size(); j++)
            {
                int dy = points[j][1] - points[i][1], dx = points[j][0] - points[i][0];
                int gcd = GCD(dy, dx);
                // use fraction string as key
                slopes[to_string(dy / gcd) + "_" + to_string(dx / gcd)]++;
            }
            for (auto &it : slopes)
            {
                currentMax = max(currentMax, it.second);
            }
            currentMax++;
            result = max(result, currentMax);
        }
        return result;
    }

    int GCD(int a, int b) // O(n)
    {
        if (b == 0)
        {
            return a;
        }
        return GCD(b, a % b);
    }
};