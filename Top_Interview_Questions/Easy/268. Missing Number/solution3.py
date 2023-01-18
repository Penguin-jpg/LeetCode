from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(1, len(nums)):
            if nums[i] - nums[i - 1] > 1:
                return i
        return 0 if nums[0] != 0 else len(nums)
