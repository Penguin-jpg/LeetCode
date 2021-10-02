class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        /*
            參考的方法
            時間複雜度O(length1*length2)、空間複雜度O(length1*length2)
            tabulation
            如果忘記怎麼做，看這部影片一定想得起來:
            https://www.youtube.com/watch?v=ASoaQq66foQ&ab_channel=BackToBackSWE
        */

        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));

        for (int i = 1; i <= text1.length(); i++)
        {
            for (int j = 1; j <= text2.length(); j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    /*
                        當目前比對的字元相同，代表長度可以+1
                        i-1和j-1的概念是因為目前這兩個字元都相同了，就將他們移除，所以要-1
                    */
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    /*
                        當目前比對的字元不同，就比較(text1[0~i],text2[0~j-1])和(text1[0~i-1],text2[0~j])誰比較大
                        概念是兩個字串選一個人移除一個字元，看兩種結果誰比較大
                    */

                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[text1.length()][text2.length()];
    }
};