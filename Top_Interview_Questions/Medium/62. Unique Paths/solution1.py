class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[1] * n] * m
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        return dp[m - 1][n - 1]


# 因為 python 的 hash map 可以用 tuple 當 key，所以能用 memo 法
# 時間: O(m*n), 空間: O(m*n)
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        memo = {}
        return self.find_paths(m - 1, n - 1, memo)

    def find_paths(self, m: int, n: int, memo: dict) -> int:
        if m == 0 or n == 0:
            return 1
        elif (m, n) in memo:
            return memo[(m, n)]
        memo[(m, n)] = self.find_paths(m - 1, n, memo) + self.find_paths(m, n - 1, memo)
        return memo[(m, n)]
