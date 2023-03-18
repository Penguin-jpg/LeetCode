from typing import List
import sys


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        return self.LIS(nums, 0, -sys.maxsize)

    def LIS(self, nums: List[int], index: int, last: int):
        if index >= len(nums):
            return 0
        take, not_take = 0, self.LIS(nums, index + 1, last)
        if nums[index] > last:
            take = 1 + self.LIS(nums, index + 1, nums[index])
        return max(take, not_take)
