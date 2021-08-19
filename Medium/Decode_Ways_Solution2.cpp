class Solution
{
public:
    int numDecodings(string &s)
    {
        /*
            參考的方法
            時間複雜度O(n)(n:字串s的長度)、空間複雜度O(n)
            iterative的版本，字的解碼方法為前面切割出一位數的方法加上前面切割出兩位數方法的總和
        */

        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            //切割出一位數
            if (s[i] != '0')
            {
                dp[i] += dp[i + 1];
            }

            //切割出兩位數
            if (i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6'))
            {
                dp[i] += dp[i + 2];
            }
        }
        return dp[0];
    }
};