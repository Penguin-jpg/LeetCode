class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        s_length, p_length = len(s), len(p)
        dp = [[False for _ in range(p_length + 1)] for _ in range(s_length + 1)]
        dp[s_length][p_length] = True
        for i in range(s_length, -1, -1):
            for j in range(p_length - 1, -1, -1):
                if j + 1 < p_length and p[j + 1] == "*":
                    dp[i][j] = dp[i][j + 2] or (
                        i < s_length and (p[j] == s[i] or p[j] == ".") and dp[i + 1][j]
                    )
                else:
                    dp[i][j] = i < s_length and (p[j] == s[i] or p[j] == ".") and dp[i + 1][j + 1]
        return dp[0][0]
