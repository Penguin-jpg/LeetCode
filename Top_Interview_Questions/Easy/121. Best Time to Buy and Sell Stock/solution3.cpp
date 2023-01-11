#include <vector>
using namespace std;

/**
 * 參考解答: Kadane's Algorithm，詳細解釋可看以下連結的一樓留言
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/solutions/39038/kadane-s-algorithm-since-no-one-has-mentioned-about-this-so-far-in-case-if-interviewer-twists-the-input/
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int maxCurrent = 0; // current max value
        int maxSoFar = 0;   // max value so far
        for (int i = 1; i < prices.size(); i++)
        {
            // add the difference of prices to current max value
            maxCurrent += prices[i] - prices[i - 1];
            // if maxCurrent is smaller than 0, set it to 0
            maxCurrent = max(0, maxCurrent);
            // update maxSoFar
            maxSoFar = max(maxSoFar, maxCurrent);
        }
        return maxSoFar;
    }
};