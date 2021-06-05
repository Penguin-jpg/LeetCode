class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            參考的方法
            上一種方法的簡化版
            其實只需要將所有能賺的金額相加，就會等於賺到的最大值
        */

        int sum=0;
        
        for(int n=1;n<prices.size();n++)
        {
            int profit=prices[n]-prices[n-1];
            if(profit>0)
            {
                sum+=profit;
            }
        }
        
        return sum;
    }
};