from typing import List


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if len(nums) == k:
            return [max(nums)]
        size = len(nums) - (k - 1)
        results = [0] * size
        for i in range(0, size):
            results[i] = max(nums[i : i + k])
        return results
