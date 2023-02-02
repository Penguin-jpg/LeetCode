from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        dp = [[0] * len(nums) for _ in range(2)]
        dp[0][0], dp[1][0] = nums[0], nums[0]
        for i in range(1, len(nums)):
            dp[0][i] = max(nums[i], nums[i] + dp[0][i - 1])
            dp[1][i] = max(dp[1][i - 1], dp[0][i])
        return dp[1][-1]
