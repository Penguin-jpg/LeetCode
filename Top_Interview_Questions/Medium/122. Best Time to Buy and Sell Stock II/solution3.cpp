#include <vector>
using namespace std;

/**
 * 想法: solution1優化版，根據概念，把所有上升區段加總即可
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int currentProfit = 0, profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            profit = prices[i] - prices[i - 1];
            currentProfit += profit > 0 ? profit : 0;
        }
        return currentProfit;
    }
};