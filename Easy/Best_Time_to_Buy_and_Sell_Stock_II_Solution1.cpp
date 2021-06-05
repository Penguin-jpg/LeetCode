class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            我的方法
            時間複雜度O(n)、空間複雜度O(1)
            只要看到更高的價格就賣出，並買入當天的股票，最後的總合就是答案
        */

        int current=prices[0];
        int sum=0;
        
        for(int n=1;n<prices.size();n++)
        {
            if(prices[n]<current)
            {
                current=prices[n];
            }else
            {
                sum+=prices[n]-current;
                current=prices[n];
            }
        }
        
        return sum;
    }
};