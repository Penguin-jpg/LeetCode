class Solution {
public:
    int numTrees(int n) {
        /*
            參考的方法1
            時間複雜度O(n^2)、空間複雜度O(n)
            dp[x]代表n=x時的所有可能
            例如n=3有三種情況:1為root,2為root,3為root
            1為root只有一種情況:
            1          可以拆成兩半看成左子樹為root=0(空的)，右子樹為root=2(3,2或2,3兩種情況)
             \         其他case也能用類似方法拆解，可得dp[n]=dp[0]*dp[n-1]+dp[1]*dp[n-2]+...+dp[n-1]*dp[0]
              2
               \
                3
        */
        if(n==1)
        {
            return 1;
        }
        
        int dp[n+1];
        //base cases
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        
        for(int k=3;k<=n;k++)
        {
            dp[k]=0;
            for(int m=0;m<k;m++)
            {
                dp[k]+=dp[m]*dp[k-m-1];
            }
        }
        
        return dp[n];
    }
};