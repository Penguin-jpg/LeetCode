from typing import List


class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        if len(nums) == 1 or nums[0] > nums[1]:
            return 0
        for i in range(1, len(nums) - 1):
            if i + 1 < len(nums) and nums[i - 1] < nums[i] and nums[i + 1] < nums[i]:
                return i
        return len(nums) - 1
