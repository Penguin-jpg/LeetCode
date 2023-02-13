#include <vector>
using namespace std;

/**
 * 想法: 用 greedy 解，假設買第 i 天的股票，若第 i+1 天的股票比第 i 天便宜，則改
 * 成購買第 i+1 天的股票，若下一天賣出會賺錢，則賣出，最後總和即為最大值
 * (為什麼局部最大值總和會是全域最大值：因為假設第 i 天到第 j 天賣出能賺到全域最
 * 大值，假設第 i+1, i+2,...,j-1 賣出均能賺錢且 prices[i+1]-prices[i] <
 * prices[i+2]-prices[i+1]...，最後總和即為 prices[j]-prices[i]，就算中途有賺有
 * 虧也是差不多的原理)
 * (更直覺的理解：為求最大利潤，絕對不可能在下跌的時候賣出股票，只可能在價格更高
 * 時賣出，把整個過程中所有上升的區段之值加起來即為最大值)
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int currentProfit = 0;
        int stock = 0; // current holding stock
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[stock] >= prices[i]) // if we buy it at higher price, then buy it at lower price
            {
                stock = i;
            }
            else // there is a profit if we sell it
            {
                currentProfit += prices[i] - prices[stock];
                stock = i;
            }
        }
        return currentProfit;
    }
};