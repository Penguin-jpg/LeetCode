from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        dp = [False for _ in range(len(nums))]
        goal = len(nums) - 1
        dp[0] = True
        for i in range(goal):
            if dp[goal]:
                return True
            elif not dp[i]:
                return False
            for j in range(1, nums[i] + 1):
                if i + j >= len(nums):
                    break
                dp[i + j] = True
        return dp[goal]
