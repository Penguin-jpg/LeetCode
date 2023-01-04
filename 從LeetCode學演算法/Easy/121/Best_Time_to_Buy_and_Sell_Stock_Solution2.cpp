class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            參考的方法
            時間複雜度O(n)、空間複雜度O(1)
            上一種方法的簡化版，直接紀錄買入時的價格
        */

        int profit=0;
        int current=prices[0];
        
        for(int n=1;n<prices.size();n++)
        {
            if(prices[n]<current)
            {
                current=prices[n];
            }else
            {
                if(prices[n]-current>profit)
                {
                    profit=prices[n]-current;
                }
            }
        }
        
        return profit;
    }
};