class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        /*
            看了那部影片後想到的方法
            時間複雜度O(length1*length2)、空間複雜度(length1*length2)
            memorization
        */

        vector<vector<int>> memo(text1.length() + 1, vector<int>(text2.length() + 1, -1));
        return recur(text1, text2, 0, 0, memo);
    }

    int recur(string &text1, string &text2, int i, int j, vector<vector<int>> &memo)
    {
        if (i >= text1.length() || j >= text2.length())
        {
            return 0;
        }

        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }

        if (text1[i] == text2[j])
        {
            memo[i][j] = 1 + recur(text1, text2, i + 1, j + 1, memo);
        }
        else
        {
            memo[i][j] = max(recur(text1, text2, i + 1, j, memo),
                             recur(text1, text2, i, j + 1, memo));
        }

        return memo[i][j];
    }
};