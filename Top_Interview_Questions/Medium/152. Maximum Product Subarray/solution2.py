from typing import List


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        result, current_max, current_min = (
            nums[0],
            [nums[0] for _ in range(len(nums))],
            [nums[0] for _ in range(len(nums))],
        )
        for i in range(1, len(nums)):
            if nums[i] < 0:
                current_max[i - 1], current_min[i - 1] = current_min[i - 1], current_max[i - 1]
            current_max[i] = max(nums[i], current_max[i - 1] * nums[i])
            current_min[i] = min(nums[i], current_min[i - 1] * nums[i])
            result = max(result, current_max[i])
        return result
