class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        /*
            參考的方法
            時間複雜度O(length1*length2)、空間複雜度O(length1*length2)
            比較text1[i]和text2[j]是否相同，如果相同就代表長度會加1，
            若不同就選擇dp[i][j-1]和dp[i-1][j]較大的那個
        */

        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));

        for (int i = 1; i <= text1.length(); i++)
        {
            for (int j = 1; j <= text2.length(); j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[text1.length()][text2.length()];
    }
};