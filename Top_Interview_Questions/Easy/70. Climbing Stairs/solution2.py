class Solution:
    def climbStairs(self, n: int) -> int:
        memo = {}
        return self.helper(n, memo)

    def helper(self, n: int, memo: dict) -> int:
        if n < 0:
            return 0
        elif n <= 1:
            return 1
        elif n in memo:
            return memo[n]
        memo[n] = self.helper(n - 1, memo) + self.helper(n - 2, memo)
        return memo[n]
