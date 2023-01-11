#include <vector>
using namespace std;

/**
 * 參考解答: 在最低的時候買進，最高的時候賣出，所以需要同時找出何時買進最低價以及何時賣出最高價
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int minBuy = INT_MAX; // lowest buy price
        int profit = 0;       // highest profit
        for (int i = 0; i < prices.size(); i++)
        {
            // price to buy today is lower than the lowest buy price
            if (prices[i] < minBuy)
            {
                minBuy = prices[i];
            }
            int currentProfit = prices[i] - minBuy; // profit if sell today
            // profit sell today is higher than the highest profit
            if (currentProfit > profit)
            {
                profit = currentProfit;
            }
        }
        return profit;
    }
};