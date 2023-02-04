class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        if m < n:
            m, n = n, m
        result, j = 1, 1
        for i in range(m, m + n - 1):
            result *= i
            result //= j
            j += 1
        return result
