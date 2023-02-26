from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        return self.rob_max(nums, len(nums) - 1)

    def rob_max(self, nums: List[int], i: int) -> int:
        if i < 0:
            return 0
        return max(self.rob_max(nums, i - 1), nums[i] + self.rob_max(nums, i - 2))
