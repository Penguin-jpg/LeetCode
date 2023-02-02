from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sum, max_sum = 0, nums[0]
        for i in range(len(nums)):
            sum = max(nums[i], nums[i] + sum)
            max_sum = max(sum, max_sum)
            sum = 0 if sum < 0 else sum
        return max_sum
