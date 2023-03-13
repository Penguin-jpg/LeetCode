import sys
import math


class Solution:
    def numSquares(self, n: int) -> int:
        dp = [sys.maxsize] * (n + 1)
        dp[0] = 0
        end = int(math.sqrt(n))
        for i in range(1, end + 1):
            square = i * i
            for j in range(square, n + 1):
                dp[j] = min(dp[j - square] + 1, dp[j])
        return dp[n]
