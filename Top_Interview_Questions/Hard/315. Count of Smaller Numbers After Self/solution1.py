from typing import List


class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        results = [0] * len(nums)
        for i in range(len(nums)):
            for j in range(i, len(nums)):
                if nums[j] < nums[i]:
                    results[i] += 1
        return results
