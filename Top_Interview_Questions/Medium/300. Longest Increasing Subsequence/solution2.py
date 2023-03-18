from typing import List


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        memo = [-1] * (len(nums) + 1)
        return self.LIS(nums, 0, -1, memo)

    def LIS(self, nums: List[int], index: int, last_index: int, memo: List[int]):
        if index >= len(nums):
            return 0
        elif memo[last_index + 1] != -1:
            return memo[last_index + 1]
        take, not_take = 0, self.LIS(nums, index + 1, last_index, memo)
        if last_index == -1 or nums[index] > nums[last_index]:
            take = 1 + self.LIS(nums, index + 1, index, memo)
        memo[last_index + 1] = max(take, not_take)
        return memo[last_index + 1]
