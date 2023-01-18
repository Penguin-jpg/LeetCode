from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        total_sum = (0 + len(nums)) * (len(nums) + 1) // 2
        current_sum = sum(nums)
        diff = total_sum - current_sum
        return 0 if diff == 0 else diff
