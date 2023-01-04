class Solution {
public:
    int numTrees(int n) {
        /*
            參考的方法2
            時間複雜度O(n^2)
            選定i為root，則左子樹範圍一定在l~(i-1)，右子樹範圍一定在(i+1)~r
            找出左子樹所有可能的組合和右子樹所有可能的組合並相乘，就能得到root=i時的答案
        */

        vector<int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        return tree(1,n,dp);
    }
    
    int tree(int l,int r,vector<int>& dp)
    {
        if(l>=r)
        {
            return 1;
        }
        
        if(dp[r-l+1]!=-1)
        {
            return dp[r-l+1];
        }
        
        int sum=0;
        
        for(int i=l;i<=r;i++)
        {
            sum+=tree(l,i-1,dp)*tree(i+1,r,dp);
        }
        dp[r-l+1]=sum;
        return dp[r-l+1];
    }
};