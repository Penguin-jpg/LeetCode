class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        dp = [[False for _ in range(n + 1)] for _ in range(m + 1)]
        dp[m][n] = True
        for i in range(m, -1, -1):
            for j in range(n - 1, -1, -1):
                if p[j] == "*":
                    dp[i][j] = dp[i][j + 1] or (i < m and dp[i + 1][j])
                else:
                    dp[i][j] = i < m and (p[j] == s[i] or p[j] == "?") and dp[i + 1][j + 1]
        return dp[0][0]
