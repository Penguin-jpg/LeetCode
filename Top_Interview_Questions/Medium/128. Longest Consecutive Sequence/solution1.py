from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        nums.sort()
        max_length, current_length = 1, 1
        for i in range(1, len(nums)):
            diff = nums[i] - nums[i - 1]
            if diff == 1:
                current_length += 1
                max_length = max(max_length, current_length)
            elif diff == 0:
                continue
            else:
                current_length = 1
        return max_length
