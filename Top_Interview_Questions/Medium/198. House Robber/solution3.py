from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        memo = [-1 for _ in range(len(nums))]
        return self.rob_max(nums, 0, memo)

    def rob_max(self, nums: List[int], i: int, memo: List[int]) -> int:
        if i >= len(nums):
            return 0
        elif memo[i] != -1:
            return memo[i]
        memo[i] = max(self.rob_max(nums, i + 1, memo), nums[i] + self.rob_max(nums, i + 2, memo))
        return memo[i]
