from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        dp = [[] for _ in range(n + 1)]
        dp[0] = [""]
        for i in range(1, n + 1):
            for j in range(0, i):
                left = dp[j]
                right = dp[i - j - 1]
                for k in range(0, len(left)):
                    for l in range(0, len(right)):
                        dp[i].append("(" + left[k] + ")" + right[l])
        return dp[n]
