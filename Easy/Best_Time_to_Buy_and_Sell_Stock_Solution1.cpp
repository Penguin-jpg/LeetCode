class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            參考後自己想的方法
            時間複雜度O(n)、空間複雜度O(1)
            將買入當天的index紀錄，如果第n天賣出會虧錢，就代表第n天在買入會比較便宜，
            反之，如果賣出會賺錢，就比較是否是最大值
        */

        int max=0;
        int current=0;
        int buyIndex=0;
        
        for(int n=1;n<prices.size();n++)
        {
            if(prices[n]-prices[buyIndex]<0)
            {
                current=0;
                buyIndex=n;
            }else
            {
                current=prices[n]-prices[buyIndex];
                if(current>max)
                {
                    max=current;
                }
            }
        }
        
        return max;
    }
};