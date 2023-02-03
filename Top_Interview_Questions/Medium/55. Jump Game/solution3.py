from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        dp = [0] * len(nums)
        goal = len(nums) - 1
        dp[0] = nums[0]
        for i in range(1, len(nums)):
            if dp[i - 1] < i:
                return False
            dp[i] = max(i + nums[i], dp[i - 1])
            if dp[i] >= goal:
                return True
        return dp[goal] >= goal
