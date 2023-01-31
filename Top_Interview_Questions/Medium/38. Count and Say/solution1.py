class Solution:
    def countAndSay(self, n: int) -> str:
        dp = [""] * (n + 1)
        dp[1] = "1"
        for i in range(2, n + 1):
            j = 0
            while j < len(dp[i - 1]):
                count = 0
                while j + 1 < len(dp[i - 1]) and dp[i - 1][j] == dp[i - 1][j + 1]:
                    count += 1
                    j += 1
                count += 1
                dp[i] += str(count) + dp[i - 1][j]
                j += 1
        return dp[n]
