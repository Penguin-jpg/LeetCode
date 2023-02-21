from typing import List


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        result, current_max, current_min = nums[0], nums[0], nums[0]
        for i in range(1, len(nums)):
            if nums[i] < 0:
                current_max, current_min = current_min, current_max
            current_max = max(nums[i], current_max * nums[i])
            current_min = min(nums[i], current_min * nums[i])
            result = max(result, current_max)
        return result
