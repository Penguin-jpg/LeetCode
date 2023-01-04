class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        /*
            參考的方法1
            時間複雜度O(n^3)、空間複雜度O(n^2)
        */

        //先將總和往前放
        for(int i=piles.size()-2;i>=0;i--)
        {
            piles[i]+=piles[i+1];
        }
        
        if(piles.size()<=2)
        {
            return piles[0];
        }
        
        //dp[i][m]:第i堆時，m的情況下能拿的最大值(m從1開始)
        vector<vector<int>> dp(piles.size(),vector<int>(((piles.size()+1)/2+1),-1));
        
        return helper(dp,piles,0,1);
    }
    
    int helper(vector<vector<int>>& dp,vector<int>& piles,int i,int m)
    {
        //最後一個的長度已經放到前面，不用再多加
        if(i==piles.size())
        {
            return 0;
        }
        
        //可以拿的數量超過目前長度
        if(2*m>=piles.size()-i)
        {
            return piles[i];
        }
        
        //已經記憶過的值可以直接回傳
        if(dp[i][m]!=-1)
        {
            return dp[i][m];
        }
        
        int minValue=INT_MAX;
        for(int x=1;x<=2*m;x++)
        {
            //找出Bob能拿的最小值(這樣Alice才會拿最多)
            minValue=min(minValue,helper(dp,piles,i+x,max(m,x)));
        }
        
        //算出Alice能拿的最大值
        dp[i][m]=piles[i]-minValue;
        
        return dp[i][m];
    }
};