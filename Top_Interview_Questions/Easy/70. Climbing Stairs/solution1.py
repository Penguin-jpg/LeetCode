class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return
        results = [0, 1, 2]
        for i in range(3, n + 1):
            results.append(results[i - 1] + results[i - 2])
        return results[-1]
