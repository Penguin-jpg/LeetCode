#include <string>
#include <vector>
using namespace std;

/**
 * 參考解答: 可以用 dp 解，透過觀察可發現其規律： dp[i] 就是一對新括號加上
 * dp[j](j=0,1,...,i-1)的排列組合，詳細解釋可以看該網址：https://leetcode.com/problems/generate-parentheses/solutions/594770/c-2-solutions-backtracking-and-dp/
 * 時間: O(n^4), 空間: O(n)
 */

class Solution
{
  public:
    vector<string> generateParenthesis(int n)
    {
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                vector<string> &left = dp[j];
                vector<string> &right = dp[i - j - 1];
                for (int k = 0; k < left.size(); k++)
                {
                    for (int l = 0; l < right.size(); l++)
                    {
                        dp[i].push_back("(" + left[k] + ")" + right[l]);
                    }
                }
            }
        }
        return dp[n];
    }
};