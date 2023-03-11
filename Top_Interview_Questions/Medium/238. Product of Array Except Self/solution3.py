from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        results = [1] * len(nums)
        suffix_product = 1
        for i in range(1, len(nums)):
            results[i] = nums[i - 1] * results[i - 1]
        for i in range(len(nums) - 1, -1, -1):
            results[i] *= suffix_product
            suffix_product *= nums[i]
        return results
