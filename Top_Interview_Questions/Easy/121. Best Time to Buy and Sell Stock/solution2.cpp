#include <vector>
using namespace std;

/**
 * 參考解答: 用 two pointer，一個當最低價的 index(left)，另一個當最高價的
 * index(right)，當 prices[left] > prices[right]，就把 left 移到 right 的位置，
 * 並將 right+1；檢查 prices[right] - prices[left] 並更新最大利潤
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int left = 0;   // point to lowest buy price
        int right = 1;  // point to highest sell price
        int profit = 0; // highest profit
        while (right < prices.size())
        {
            if (prices[left] < prices[right]) // profitable
            {
                profit = max(profit, prices[right] - prices[left]);
            }
            else // prices[left] is not the best price to buy
            {
                left = right;
            }
            right++;
        }
        return profit;
    }
};